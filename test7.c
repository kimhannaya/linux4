#include <stdio.h> 

/*
void swap_ptr(char **ppa, char **ppb);

int main(void)
{
    char *pa = "succes";
    char *pb = "failure";


    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;

}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}

------이중 포인터 활용2------
void print_str(char **pps, int cnt);

int main(void)
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);

    print_str(ptr_ary, count);

    return 0;
}

void print_str(char **pps, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("%s\n", pps[i]);
    }
}

------2차원 배열과 배열 포인터------
void print_ary(int (*)[4]);

int main(void)
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    
    print_ary(ary);

    return 0;
}

void print_ary(int (*pa)[4])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}

------함수 포인터의 활용------
void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void)
{
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
    scanf("%d", &sel);

    switch(sel)
    {
    case 1 : func(sum); break;
    case 2 : func(mul); break;
    case 3 : func(max); break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결과값은 : %d\n", res);
}

int sum(int a, int b)
{
    return (a + b);
}

int mul(int a, int b)
{
    return (a * b);
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

------구조체의 멤버를 다른 구조체 사용------

struct profile
{
    int age;
    double height;
};

struct student
{
    struct  profile pf;
    int id;
    double grade;
    
};

int main(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n", yuni.pf.age);
    printf("키 : %.1f\n", yuni.pf.height);
    printf("학번 : %d\n", yuni.id);
    printf("학점 : %.1f\n", yuni.grade);

    return 0;

}

------구조체 배열을 처리하는 함수------*/

struct address
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];

};

void print_list(struct address *lp);

int main(void)
{
    struct address list[5] = {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순신", 35, "222-2222", "서울 건천동"},
        {"장보고", 19, "333-3333", "완도 청해진"},
        {"유관순", 15, "444-4444", "충남 천안 "},
        {"안중근", 45, "555-5555", "황해도 해주"}
    };

    print_list(list);

    return 0;
    
}

void print_list(struct address *lp)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n",
            (lp+i)->name, (lp+i)->age, (lp+i)->tel, (lp+i)->addr);
    }
}