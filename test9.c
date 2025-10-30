#include <stdio.h>
#include <string.h>
#include <math.h>

/*
int main(void)
{
    FILE *fp;
    char line_buffer[1024]; // 한 줄을 읽어올 임시 저장 공간
    const char *filename = "fast_log.txt"; // 읽어올 로그 파일 이름

    // 1. 파일을 "r" (읽기) 모드로 열기
    fp = fopen(filename, "r"); 

    if (fp == NULL) 
    {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return 1; // 파일 열기 실패
    }

    printf("--- 로그에서 감지된 IPv4 주소 ---\n");

    // 2. 파일 끝(EOF)에 도달할 때까지 한 줄씩 읽기
    while (fgets(line_buffer, sizeof(line_buffer), fp) != NULL) 
    {
        // 3. "{ICMP}" 문자열이 있는지 확인 (IPv4 로그만 필터링)
        //    (IPv6 로그는 "{IPv6-ICMP}"이므로 이 if문에 걸리지 않음)
        if (strstr(line_buffer, "{ICMP}") != NULL) 
        {
            char *arrow_ptr = strstr(line_buffer, " -> "); // " -> " 위치 찾기
            char *brace_ptr = strchr(line_buffer, '}');    // "}" 위치 찾기

            // 4. 화살표와 괄호가 모두 발견되었는지 확인
            if (arrow_ptr != NULL && brace_ptr != NULL)
            {
                // 5. IP 주소 문자열의 시작 위치 계산
                char *src_ip_start = brace_ptr + 2; // "}"와 공백 다음
                char *dst_ip_start = arrow_ptr + 4; // " -> "와 공백 다음

                int ip_src[4], port_src;
                int ip_dst[4], port_dst;

                // 6. [핵심] sscanf로 문자열에서 IP와 포트 번호 추출
                //    형식: "192.168.160.1:8"
                int src_count = sscanf(src_ip_start, "%d.%d.%d.%d:%d", 
                                       &ip_src[0], &ip_src[1], &ip_src[2], &ip_src[3], &port_src);
                
                int dst_count = sscanf(dst_ip_start, "%d.%d.%d.%d:%d",
                                       &ip_dst[0], &ip_dst[1], &ip_dst[2], &ip_dst[3], &port_dst);

                // 7. 5개 항목(IP 4개, 포트 1개)이 모두 잘 읽혔다면 출력
                if (src_count == 5 && dst_count == 5)
                {
                    printf("Src: %d.%d.%d.%d (Port: %d) -> Dst: %d.%d.%d.%d (Port: %d)\n",
                           ip_src[0], ip_src[1], ip_src[2], ip_src[3], port_src,
                           ip_dst[0], ip_dst[1], ip_dst[2], ip_dst[3], port_dst);
                }
            }
        }
    }

    // 8. 파일 닫기
    fclose(fp);

    return 0;
}

------이동로봇 종합 계산 프로그램------*/

struct robot{
    double L;
    double r;
    int kg;
    double energy;
    int V;
    int A;
    int Ah;
    double h;
    int v;
    double vl;
    int w;
    double wl;
    int mN;
    int a;
    double g = 9.8;
    double sin = 0.5;
    double T_slope;
    double T_accel;
    


};
typedef struct robot Robot;

void info(Robot *ps);
void wheel_speed(Robot *ps);
void battery_use(Robot *ps);
void motor(Robot *ps);
void sensor(Robot *ps);
void error(Robot *ps);
void menu(Robot *ps);



int main(void)
{
    Robot my_robot;

    info(&my_robot);

    int choice = -1;


    while(choice != 0)
    {
        printf("=== 이동로봇 종합 계산기 ===\n");
        printf("1. 바퀴별 속도 계산 (v, w -> vl, vr)\n");
        printf("2. 배터리 사용 시간 계산\n");
        printf("3. 모터 토크 계산\n");
        printf("4. 센서 정규화 계산\n");
        printf("5. 오차율 계산\n");
        printf("0. 종료\n");
        printf("메뉴 선택 : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: wheel_speed(&my_robot); break; 
            case 2: battery_use(&my_robot); break; 
            case 3: motor(&my_robot); break; 
            case 4: sensor(&my_robot); break; 
            case 5: error(&my_robot); break; 
            case 0: break; 
        }
    }
    return 0;
}
void info(Robot *ps)
{
    printf("=== 이동로봇 기본 사양 입력 ===\n");
    printf("바퀴 간 거리 L [m] : ");
    scanf("%lf", &ps -> L);
    printf("바퀴 반지름 r [m] : ");
    scanf("%lf", &ps -> r);
    printf("로봇 질량 [kg] : ");
    scanf("%d", &ps -> kg);

}

void wheel_speed(Robot *ps)
{
    printf("직진 속도 [v] : ");
    scanf("%d", &ps -> v);
    printf("각속도 [w] : ");
    scanf("%d", &ps -> w);
    ps -> vl = ps -> v - (ps -> w* ps -> L/ 2);
    ps -> wl = ps -> (ps -> vl / ps -> r);

    printf("바퀴 선속도 : %.2f", ps -> vl);
    printf("모터 각속도 : %.2f", ps -> wl);
}

void battery_use(Robot *ps)
{
    printf("전압 [V] : ");
    scanf("%d", &ps -> V);
    printf("소모 전류 [A] : ");
    scanf("%d", &ps -> A);
    printf("배터리 용량 [Ah] : ");
    scanf("%d", &ps -> Ah);
    ps -> h = ps -> Ah / ps -> A;
    ps -> energy = ps -> Ah * ps -> V;
    printf("총 사용 가능 시간 : %.2f\n", ps -> h);
    printf("총 에너지 용량 : %.2f Wh", ps -> energy);
}

void motor(Robot *ps)
{
    printf("가속 토크 : ");

    ps -> T_accel = (ps -> kg * ps -> a) * r;
    printf("가속 토크 : ");
    ps -> T_slope = (ps -> kg * ps -> g * ps -> sin) * r;
    printf("경사 토크 : ");
    

    scanf("%d", &ps -> kg);
}
void sensor(Robot *ps)
{
    printf("로봇 질량 [kg] : ");
    scanf("%d", &ps -> kg);
}
void error(Robot *ps)
{
    printf("로봇 질량 [kg] : ");
    scanf("%d", &ps -> kg);
}
void menu(Robot *ps)
{
    printf("로봇 질량 [kg] : ");
    scanf("%d", &ps -> kg);
}
