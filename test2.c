#include <stdio.h>
#include <math.h>
int main(void) {
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

    return 0;
}
