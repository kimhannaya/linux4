#include <stdio.h>

/*int main(void)
{
    int a = 10;
    int *p = &a;
    double *pd;

    pd = p;
    printf("%lf\n", *pd);

    return 0;
}

------다른 함수의 변수 사용하기------

void swap(void);

int main(void)
{
    int a = 10, b = 20;

    swap();
    printf("a:%d, b:%d\n", a, b);

    return 0;

}

void swap(void)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}
    
------문제------

void swap(double *pa, double *pd);
void line_up(double *maxp, double *midp, double *minp);

int main(void){
    double max, mid, min;

    printf("실수값 3개 입력 : ");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("정렬된 값 출력 : %.1f, %.1f, %.1f\n", max, mid, min);

    return 0;

}

void swap(double *pa, double *pb)
{
    double temp;
    temp= *pa;
    *pa = *pb;
    *pb = temp;    
}

// 3개의 값을 내림차순으로 정렬(line_up)하는 함수 (수정됨)
void line_up(double *maxp, double *midp, double *minp)
{
    // 1. maxp가 midp보다 작으면 교환
    // (이 비교 후, maxp는 둘 중 큰 값을 가짐)
    if (*maxp < *midp) {
        swap(maxp, midp);
    }
    
    // 2. maxp가 minp보다 작으면 교환
    // (이 비교 후, maxp는 3개 중 가장 큰 값을 가짐)
    if (*maxp < *minp) {
        swap(maxp, minp);
    }
    
    // 3. maxp는 이제 가장 큰 값이므로,
    //    midp와 minp만 비교해서 정렬
    if (*midp < *minp) {
        swap(midp, minp);
    }
}

------배열의 값을 출력하는 함수------

void print_ary(int *pa, int size);

int main(void)
{
    int ary1[5] = { 10, 20, 30, 40, 50 };
    int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };
    
    int size1 = sizeof(ary1) / sizeof(ary1[0]); // 20 / 4 = 5
    int size2 = sizeof(ary2) / sizeof(ary2[0]);
    print_ary(ary1, size1);
    printf("\n");
    print_ary(ary2, size2);

    return 0;
}

void print_ary(int *pa, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", pa[i]);
    }
}

------scanf 함수가 문자를 입력하는 과정------*/

int main(void)
{
    char ch;
    int i;

    for (i = 0; i < 3; i++)
    {
        scanf("%c", &ch);
        printf("%c", ch);
    }

    return 0;
}