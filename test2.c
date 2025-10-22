#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/*
int pause(void) {
     double m, Tm, G, eta, r, c, SF;
    int Nm;
    const double g = 9.81;
    printf("총 질량 m(kg): ");
    scanf("%lf", &m);
    printf("모터 정격토크 Tm(N·m): "); if (scanf("%lf", &Tm) != 1);
    printf("구동 모터 수 Nm: ");
    scanf("%d", &Nm);
    printf("감속비 G: "); 
    scanf("%lf", &G);
    printf("구동 효율 eta(0~1): "); 
    scanf("%lf", &eta);
    printf("바퀴 반지름 r(m): "); 
    scanf("%lf", &r);
    printf("구름계수 c(예:0.1~0.2): ");
    scanf("%lf", &c);
    printf("안전계수 SF(>=1): ");
    scanf("%lf", &SF);
    
    double T_tot = Nm * Tm * G * eta; // 총 구동 토크 [N·m]
    double F_avail = T_tot / r; // 가용 견인력 [N]

    double sin_theta = (F_avail / SF - c * m * g) / m * g;
    if (sin_theta < 0.0) sin_theta = 0.0;
    if (sin_theta > 1.0) sin_theta = 1.0;
    double theta_rad = asin(sin_theta);
    double theta_deg = theta_rad * 180.0 / 3.141592;
    double grade_pct = tan(theta_rad) * 100.0;
    // 결과 출력
    printf("\n[결과]\n");
    printf("총 구동 토크 T_tot : %.2f N·m\n", T_tot);
    printf("가용 견인력 F_avail : %.2f N\n", F_avail);
    printf("등판 가능 최대각 : %.2f deg\n", theta_deg);
    printf("등판율(grade) : %.1f %%\n", grade_pct);
    printf("가정: 마찰한계 무시, 구름저항 c 포함, 안전계수");
  
    

--------P59--------
#define EARNED_INCOME_TAX_RATE 4
#define LOCAL_INCOME_TAX_RATE 10
#define NATIONAL_PENSION_RATE 4.5
#define EMPLOYMENT_INSURANCE_RATE 0.8
#define HEALTH_INSURANCE_RATE 3.38

int main(void)
{
    float salary;
    float eit, lit, np, ei, hi;
    float total;

    printf("This program calculates social insurance tax.\n");
    printf("Please enter your salary(month): ");
    scanf("%f", &salary);

    eit = salary * (EARNED_INCOME_TAX_RATE / 100.0);
    lit = eit * (LOCAL_INCOME_TAX_RATE / 100.0);
    np = salary * (NATIONAL_PENSION_RATE / 100.0);
    ei = salary * (EMPLOYMENT_INSURANCE_RATE / 100.0);
    hi = salary * (HEALTH_INSURANCE_RATE / 100.0);
    total = eit + lit + np + ei + hi;

    printf("\nEarned income tax:     %10d Won\n", (int)eit);
    printf("Local income tax:      %10d Won\n", (int)lit);
    printf("National pension:      %10d Won\n", (int)np);
    printf("Employment insurance:  %10d Won\n", (int)ei);
    printf("Health tax:            %10d Won\n", (int)hi);
    printf("--------------------------------\n", (int)eit);
    printf("Total:                 %10d Won\n", (int)total);

    return 0;


------재귀호출------
void fruit(int count);
int main(void)
{
    fruit(1);
    return 0;
}

void fruit(int count)
{
    printf("apple\n");
    if (count == 3) return;
    fruit(count + 1);
    printf("jam\n");
}
------재귀호출예제(값을 입력받고 값만큼 더해서 출력)------
void num(int count);
int main(void)
{
    num(1);
    return 0;
}
void num(int count)
{
    printf("%d\n", num);
    if (count == 1) return;
    num(count + 1);
}
    
------배열과 반복문------

int main(void)
{
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score) / sizeof(score[0]);


    for (i = 0; i < count; i++)
    {
        scanf("%d", &score[i]);
    }
    for (i = 0; i < count; i++)
    {
        total += score[i];
    }
    avg = total / (double)count;

    for (i = 0; i < count; i++)
    {
        printf("%5d", score[i]);
    }
    printf("\n");

    printf("평균:%.1lf\n", avg);

    return 0;
}
------360도 라이다에서 최소거리/방향 찾기------


int main(void) 
{
double dist[360];
int i, min_index = 0;
double min_value1, min_value2, min_value3;
printf("360° 라이다 거리값 입력 (테스트용으로 10개만 입력 가능)\n");
for (i = 0; i < 10; i++) { // 실제는 360개지만 실습용으로 10개만 입력
printf("%3d° 거리(cm): ", i);
scanf("%lf", &dist[i]);
}
min_value1 = dist[0];
for (i = 1; i < 10; i++) {
if (dist[i] < min_value1) {
min_value1 = dist[i];
min_index = i;
}
}
printf("\n[라이다 최소 거리 탐색 결과]\n");
printf("가장 가까운 거리: %.1f cm\n", min_value);
printf("장애물 방향: %d°\n", min_index);
return 0;
}

------360도 라이다에서 최소거리/방향 찾기 (가까운 거리 3개 출력)------*/


int main(void) 
{
double dist[360];
int i, j, k, min_index1 = 0, min_index2 = 0, min_index3 = 0;
double min_value1, min_value2, min_value3;
printf("360° 라이다 거리값 입력 (테스트용으로 10개만 입력 가능)\n");
for (i = 0; i < 5; i++) { // 실제는 360개지만 실습용으로 10개만 입력
printf("%3d° 거리(cm): ", i);
scanf("%lf", &dist[i]);
}
min_value1 = dist[0];
min_value2 = dist[1];
min_value3 = dist[2];
for (i = 1; i < 5; i++) {
    if (dist[i] < min_value1) {
        min_value1 = dist[i];
        min_index1 = i;
    }
    for (j = 1; j < 5; j++) {
        if ((dist[i] < min_value2) && (dist[j] < min_value2)) {
            min_value2 = dist[j];
            min_index2 = j;
        }
        /*for (k = 1; k < 10; k++) {
            if ((dist[j] < min_value3) || (min_value2 < dist[k])) {
                min_value3 = dist[k];
                min_index3 = k;
            }
        }*/
    }   
}


printf("\n[라이다 최소 거리 탐색 결과]\n");
printf("가장 가까운 거리: %.1f cm\n", min_value1);
printf("장애물 방향: %d°\n", min_index1);
printf("2번째로 가까운 거리: %.1f cm\n", min_value2);
printf("장애물 방향: %d°\n", min_index2);
return 0;
}