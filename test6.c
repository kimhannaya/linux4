#include <stdio.h>
#include <string.h>

/*int main(void)
{
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);
    getchar();
    printf("학점 입력 : ");
    grade = getchar();
    printf("학번 : %d, 학점 : %c", num, grade);

    return 0;
}

------scanf 함수를 사용한 문자열 입력------

int main(void)
{
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("첫 번째 단어 : %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

    printf("공백이 포함된 문자열 입력 : ");
    fgets(str, sizeof(str), stdin);
    //나중에 입력할 공간
    printf("입력된 문자열은 %s입니다\n", str);
    return 0;
    
}

------문자열을 붙이는 strcat, strncat 함수------

int main(void)
{
    char str[80] = "straw";


    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);

    return 0;
    
}

------전역 변수------

void assign10(void);
void assign20(void);

int a;

int main(void)
{
    printf("함수 호출 전 a 값 : %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a 값 : %d\n", a);

    return 0;
}

------레지스터 변수------

int main(void)
{
    register int i;
    int sum = 0;

    for(i = 1; i <= 10000; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}

------3차원 배열------

int main(void)
{
    int score[2][3][4] = {
        {{72, 80, 95, 68},  {68, 98, 83, 90},   {75, 72, 84, 90}},
        {{66, 85, 90, 88},  {95, 92, 88, 95},   {43, 72, 56, 75}}
    };

    int i, j, k;

    for (i=0; i < 2; i++)
    {
        printf("%d반 점수...\n", i+1);
        for(j=0; j<3; j++)
        {
            for(k=0; k<4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
            printf("\n");

    }
    return 0;

}

------가로세로의 합 구하기------*/

int main() {
    // 1. 5행 6열 2차원 배열 선언 (모든 요소를 0으로 초기화)
    int arr[5][6] = {0}; 
    
    int count = 1; // 1부터 20까지 채울 숫자

    // 2. 1~20 초기화 및 가로/세로/총합 동시 계산
    for (int i = 0; i < 4; i++) { // 0~3행 (4개 행)
        for (int j = 0; j < 5; j++) { // 0~4열 (5개 열)
            
            // 2-1. 데이터 저장 (1~20)
            arr[i][j] = count;
            
            // 2-2. 가로 합 (마지막 열(인덱스 5)에 누적)
            arr[i][5] += count;
            
            // 2-3. 세로 합 (마지막 행(인덱스 4)에 누적)
            arr[4][j] += count;
            
            // 2-4. 총 합 (마지막 행, 마지막 열(인덱스 4, 5)에 누적)
            arr[4][5] += count;

            count++; // 다음 숫자로
        }
    }

    // 3. 전체 배열 출력
    printf("--- 배열 결과 출력 ---\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d\t", arr[i][j]); 
        }
        printf("\n"); // 한 행이 끝나면 줄바꿈
    }

    return 0;
}