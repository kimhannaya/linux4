
/*------IR센서 반사값 임계치 분류기------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void classify_by_threshold(const int value[], int label[], int n, int threshold);
int count_black(const int label[], int n);
double average_index_of_black(const int label[], int n);

int main(void)
{
    int N, i, threshold;

    // 1. N을 먼저 입력받습니다.
    printf("N = ");
    scanf("%d", &N);

    // 2. N을 알게 된 후에 배열을 선언합니다. (매우 중요!)
    int value[N];
    int label[N];

    // 3. N개의 value 값을 '반복문'으로 입력받습니다.
    printf("value = ");
    for (i = 0; i < N; i++) {
        scanf("%d", &value[i]);
    }

    // 4. threshold 값을 입력받습니다.
    printf("threshold = ");
    scanf("%d", &threshold);

    // 5. 계산에 사용할 변수들을 '0'으로 초기화합니다. (매우 중요!)
    int black_count = 0;
    double sum_index = 0.0; // 합계는 double로 하는 것이 안전
    double index_avg = 0.0;

    printf("\n--- 분석 결과 ---\n");

    // 6. N번 반복하면서 모든 작업을 한 번에 처리합니다.
    printf("label = ");
    for (i = 0; i < N; i++) {
        
        // 요구사항 1: threshold 기준으로 label[] 생성
        if (value[i] < threshold) {
            label[i] = 1; // 1 (검은색 라인)
        } else {
            label[i] = 0; // 0 (흰색 바탕)
        }

        // label[i] 값을 생성 즉시 출력 (출력 예시와 동일하게)
        printf("%d ", label[i]);

        // 요구사항 2, 3: black_count 및 sum_index 계산
        if (label[i] == 1) {
            black_count++;      // black_count += label[i]와 동일
            sum_index += i;     // sum_index += (i * label[i])와 동일
        }
    }
    printf("\n"); // 줄바꿈

    // 요구사항 3: black_count 출력
    printf("black_count = %d\n", black_count);

    // 요구사항 4, 5: 라인 감지 여부에 따라 분기
    if (black_count == 0) {
        printf("라인 없음\n");
    } else {
        // 평균 계산 (반드시 black_count가 0이 아닐 때만!)
        index_avg = sum_index / (double)black_count; // 정수/정수 나눗셈 방지
        printf("index_avg = %.2f\n", index_avg);
    }

    return 0;
}
------ADC 원시값 -> 전압/거리 변환기------
#include <stdio.h>

/**
 * @brief ADC 값을 전압(Voltage)으로 변환합니다.
 * @param adc_val 원시 ADC 값 (예: 120)
 * @param v_ref 기준 전압 (예: 5.0)
 * @return 변환된 전압 값
 * * [요구사항 반영]
 * 1. 수식: (ADC 값 / 1023) * V_ref
 * 2. 예외 처리: 전압이 0이면 0.01로 제한
 
double adc_to_voltage(int adc_val, double v_ref)
{
    // (int / int) 정수 나눗셈을 방지하기 위해 1023.0 (실수)으로 나눔
    double voltage = ((double)adc_val / 1023.0) * v_ref;

    // "전압 = 0이면 나눗셈이 불가능하므로 최소 0.01 이상으로 제한"
    if (voltage == 0.0) {
        return 0.01;
    }
    
    return voltage;
}

/**
 * @brief 전압(Voltage)을 거리(Distance)로 변환합니다.
 * @param voltage_val 전압 값 (adc_to_voltage에서 계산됨)
 * @param k_val 센서 특성 상수 k (예: 27.0)
 * @return 계산된 거리 값
 *
 * [요구사항 반영]
 * 1. 수식: k / 전압
 
double voltage_to_distance(double voltage_val, double k_val)
{
    // adc_to_voltage 함수에서 이미 0.01로 처리했기 때문에
    // 여기서는 0으로 나누는 경우가 발생하지 않습니다.
    return k_val / voltage_val;
}


int main(void)
{
    int N, i;
    double Vref, k;

    // 1. N 입력
    printf("N = ");
    scanf("%d", &N);

    // 2. N 크기에 맞게 3개의 배열 선언
    int    adc_array[N];      // 입력받을 ADC 정수 배열
    double voltage_array[N];  // 계산 결과를 저장할 전압 배열
    double distance_array[N]; // 계산 결과를 저장할 거리 배열

    // 3. ADC 값 입력 (N번 반복)
    printf("adc = ");
    for (i = 0; i < N; i++) {
        scanf("%d", &adc_array[i]); // int 배열에 %d로 저장
    }

    // 4. Vref, k 입력 (오타 수정: Vrec -> Vref)
    printf("Vref = ");
    scanf("%lf", &Vref);
    printf("k = ");
    scanf("%lf", &k);

    // 5. [핵심 로직] N번 반복하며 함수를 호출해 배열에 값 저장
    for (i = 0; i < N; i++) {
        // 요구사항: 함수 사용
        voltage_array[i] = adc_to_voltage(adc_array[i], Vref);
        distance_array[i] = voltage_to_distance(voltage_array[i], k);
    }

    // 6. [출력] 이미지 예시와 동일한 형식으로 출력
    printf("\n--- 출력 결과 ---\n");
    
    // ADC 값 출력
    printf("ADC\t= "); // \t는 탭(일정 간격 띄우기)
    for (i = 0; i < N; i++) {
        printf("%-8d", adc_array[i]); // 8칸을 잡고 왼쪽 정렬
    }
    
    // 전압(V) 값 출력 (실수, 소수점 2자리)
    printf("\n전압(V)\t= ");
    for (i = 0; i < N; i++) {
        printf("%-8.2f", voltage_array[i]); // %.2f
    }
    
    // 거리(cm) 값 출력 (실수, 소수점 2자리)
    printf("\n거리(cm)= ");
    for (i = 0; i < N; i++) {
        printf("%-8.2f", distance_array[i]); // %.2f
    }
    printf("\n");

    return 0;
}

------포인터와 간접 참조 연산자-------
int main(void)
{
    int a;
    int *pa;

    pa = &a;
    *pa = 10;

    printf("포인터로 a값 출력 : %d\n", *pa);
    printf("변수명0로 a값 출력 : %d\n", a);
}
------const를 사용한 포인터------
int main(void)
{
    int a=10, b=20;
    const int *pa=&a;
    

    printf("변수 a값  : %d\n", *pa);
    pa = &b;
    printf("변수 b값 : %d\n", *pa);
    pa = &a;
    a=20;
    printf("변수 a값 : %d\n", *pa);

    return 0;
}
------주소와 포인터의 크기------
int main(void)
{
    int in;
    char ch;
    double db;

    char *pc = &ch;
    int *pi = &db;
    double *pd = &db;

    printf("char형 변수의 주소 크기  : %d\n", sizeof(&ch));
    printf("int형 변수의 주소 크기  : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기  : %d\n", sizeof(&db));

    printf("char * 포인터의 크기  : %d\n", sizeof(pc));
    printf("int * 포인터의 크기  : %d\n", sizeof(pi));
    printf("double * 포인터의 크기  : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pd));

    return 0;
}
------주소와 포인터의 크기------*/
int main(void)
{
    char ch;
    int in;
    double db;

    char *pc = &ch;
    int *pi = &db;
    double *pd = &db;

    printf("char형 변수의 주소 크기  : %d\n", sizeof(&ch));
    printf("int형 변수의 주소 크기  : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기  : %d\n", sizeof(&db));

    printf("char * 포인터의 크기  : %d\n", sizeof(pc));
    printf("int * 포인터의 크기  : %d\n", sizeof(pi));
    printf("double * 포인터의 크기  : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기  : %d\n", sizeof(*pd));

    return 0;
}