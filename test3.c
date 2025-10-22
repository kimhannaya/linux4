/*------난수 사용------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int r1 = rand() % 10;
    int r2 = rand() % 100 + 1;
    int r3 = rand() % 21 - 10;

    printf("0~9 랜덤 : %d\n", r1);
    printf("1~100 랜덤 : %d\n", r2);
    printf("-10~10 랜덤 : %d\n", r3);

    return 0;
}