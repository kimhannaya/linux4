#include <stdio.h>

int main(void) {
    double sf = 2.0, dm = 1.2, r, R, c = 0.018, g = 9.81, G;
    int n, m;
    printf("총하중(kg) : ");
    scanf("%d", &m);
    printf("구동 바퀴 수 : ");
    scanf("%d", &n);
    printf("모터 정격 토크 : ");
    scanf("%lf", &r);
    printf("감속비 : ");
    scanf("%lf", &G);
    printf("바퀴 반지름(r) : ");
    scanf("%lf", &R);

    double w = m * g;
    double F_min = c  * w * sf * dm;
    double F_motor = (r * G) * n / R;
    printf("필요한 최소 견인력 : %.2f\n", F_min);
    printf("모터가 낼 수 있는 견인력 : %.2f\n", F_motor);

    if (F_min <= F_motor)
    {
        printf("만족 굿굿");
    }
    else
    {
        printf("불만족 우우");
    }


    return 0;
}