/*------난수 사용------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
/*int main(void) {
    srand(time(NULL));

    int r1 = rand() % 10;
    int r2 = rand() % 100 + 1;
    int r3 = rand() % 21 - 10;

    printf("0~9 랜덤 : %d\n", r1);
    printf("1~100 랜덤 : %d\n", r2);
    printf("-10~10 랜덤 : %d\n", r3);

    return 0;
}

------로그에서 급가속/급제동------

int main(void) {
    // 1. 변수 선언 및 초기화
    
    const int NUM_DATA = 10; // 입력받을 데이터 개수 (상수로 정의)
    int i;
    double speed[NUM_DATA]; // 10칸짜리 배열 (speed[0] ~ speed[9])
    double delta;           // 'int'가 아닌 'double'로 변경
    
    int count_accel = 0;    // 1. 급가속 카운터 (int로 변경 및 0으로 초기화)
    int count_decel = 0;    // 1. 급제동 카운터 (int로 변경 및 0으로 초기화)

    // 2. 데이터 입력 (scanf)
    // 2. [수정] i=0 부터 NUM_DATA-1 (즉, 0~9)까지 입력받음
    printf("%d개의 속도 데이터를 입력하세요:\n", NUM_DATA);
    for(i = 0; i < NUM_DATA; i++) {
        printf("%d: ", i + 1); // 사용자에겐 1~10으로 보여줌
        scanf("%lf", &speed[i]); // speed[0]부터 차례대로 저장
    }
    
    // 3. 속도 변화량 분석
    // 2. [수정] i=1 부터 시작 (speed[1] - speed[0] 비교)
    for (i = 1; i < NUM_DATA; i++) { 
        // 4. [수정] delta 타입을 double로 계산
        delta = speed[i] - speed[i-1]; 
        
        if (delta >= 10) {
            count_accel += 1; // 1. 초기화된 변수에 더함
        } 
        // 3. [수정] 논리 오류 수정 (<= 10  ->  <= -10)
        else if (delta <= -10) { 
            count_decel += 1;
        }
    }
    
    // 4. 결과 출력
    // 4. [수정] int 타입이므로 %d로 출력
    printf("\n--- 분석 결과 ---\n");
    printf("급가속 횟수 : %d 회\n", count_accel);
    printf("급제동 횟수 : %d 회\n", count_decel);

    return 0;
}

------로그에서 급가속/급제동 (rand)------

int main(void) {
    // --- 1. 설정 및 초기화 ---
    const int NUM_POINTS = 25;       // 총 생성할 속도 데이터 개수 (25개)
    const int NUM_DELTAS = NUM_POINTS - 1; // 총 변화량 개수 (24개)
    const int MIN_ACCEL = 10;        // 최소 '일반 증가' 횟수
    const int MIN_DECEL = 10;        // 최소 '일반 감속' 횟수

    double speed[NUM_POINTS]; // 속도 데이터를 저장할 배열
    int actions[NUM_DELTAS];  // 속도 변화 '계획'을 저장할 배열 (1: 증가, -1: 감속)

    int i, j, temp_action;

    // rand() 함수 시드 초기화 (매번 다른 난수 생성)
    srand((unsigned int)time(NULL)); 

    // --- 2. 속도 변화 '계획' 생성 ---
    // (요구사항: 최소 증가 10, 최소 감속 10)
    
    // 10개는 '증가'로 채우기
    for (i = 0; i < MIN_ACCEL; i++) {
        actions[i] = 1; 
    }
    // 10개는 '감속'으로 채우기
    for (i = MIN_ACCEL; i < MIN_ACCEL + MIN_DECEL; i++) {
        actions[i] = -1;
    }
    // 나머지 4개 (24 - 10 - 10)는 랜덤으로 채우기
    for (i = MIN_ACCEL + MIN_DECEL; i < NUM_DELTAS; i++) {
        actions[i] = (rand() % 2 == 0) ? 1 : -1;
    }

    // --- 3. '계획'을 무작위로 섞기 (Shuffle) ---
    // (증가 10번 -> 감속 10번 순서가 아니도록 섞음)
    for (i = 0; i < NUM_DELTAS; i++) {
        j = rand() % NUM_DELTAS; // 섞을 대상 인덱스
        
        // actions[i]와 actions[j]를 교환
        temp_action = actions[i];
        actions[i] = actions[j];
        actions[j] = temp_action;
    }

    // --- 4. '계획'에 따라 speed 데이터 생성 ---
    printf("--- 1. 랜덤 속도 데이터 생성 (총 %d개) ---\n", NUM_POINTS);
    
    // 시작 속도 (예: 50.0)
    speed[0] = 50.0;
    printf("  0: %.1f km/h\n", speed[0]);

    for (i = 0; i < NUM_DELTAS; i++) {
        // 속도 변화량(delta) 생성
        // 0.1 ~ 9.9 사이의 난수 생성 (급가속/급감속 방지)
        double magnitude = ((double)rand() / RAND_MAX) * 9.8 + 0.1;
        
        double delta = magnitude * actions[i]; // '계획'에 따라 부호(방향) 적용
        
        speed[i+1] = speed[i] + delta;

        // 속도가 0 미만으로 내려가지 않도록 방지 (현실 반영)
        if (speed[i+1] < 0) {
            speed[i+1] = 0.0;
        }

        printf("%3d: %.1f km/h (변화량: %+.1f)\n", i+1, speed[i+1], speed[i+1] - speed[i]);
    }

    // --- 5. 생성된 데이터 분석 (기존 코드 응용 및 수정) ---
    // (기존 코드의 a, b 변수 -> 정수형 카운터로 변경)
    int count_rapid_accel = 0; // 급가속 (a)
    int count_rapid_decel = 0; // 급감속 (b)
    int count_normal_accel = 0; // 일반 증가 (요구사항)
    int count_normal_decel = 0; // 일반 감속 (요구사항)

    double delta_check;

    // i=1 부터 시작해서 [i]와 [i-1]을 비교
    for (i = 1; i < NUM_POINTS; i++) {
        delta_check = speed[i] - speed[i-1];

        // 1. 급가속/급감속 (발생하면 안 됨)
        if (delta_check >= 10.0) {
            count_rapid_accel++;
        } 
        else if (delta_check <= -10.0) {
            count_rapid_decel++;
        }
        // 2. 일반 증가/감속 (요구사항)
        else if (delta_check > 0) { // (0 < delta < 10)
            count_normal_accel++;
        }
        else if (delta_check < 0) { // (-10 < delta < 0)
            count_normal_decel++;
        }
    }

    // --- 6. 최종 결과 출력 ---
    printf("  - 급가속 (delta >= 10)  : %d 회\n", count_rapid_accel);
    printf("  - 급감속 (delta <= -10) : %d 회\n", count_rapid_decel);
    printf("  - 일반 증가 (0 < delta < 10)  : %d 회\n", count_normal_accel);
    printf("  - 일반 감속 (-10 < delta < 0) : %d 회\n", count_normal_decel);
    return 0;
}
------배터리 잔량 히스테리시스 경보 시스템------*/
int main(void)
{
    int n, i;
    int level;
    double battery[100];
    int warning = 0;
    battery[0] = 0;
   
    for (i = 0; i < 10; i++) {
        printf("배터리 잔량 입력 : ");
        scanf("%d", &battery[i]);
        level = battery[i];

        if (level <= 30) {
            warning == 0;
            if (warning == 0) {
                printf("ON\n");
            }
            else if (warning == 1) {
                printf("OFF\n");
            }
        }
        else if (level >= 35) {
            warning == 1;
            if (warning == 0) {
                printf("ON\n");
            }
            else if (warning == 1) {
                printf("OFF\n");
            }
        }
    }
}
