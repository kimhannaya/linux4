#include <stdio.h>
#include <string.h>

/*------typedef를 사용한 형 재정의------
struct student 
{
    int num;
    double grade;
};

typedef struct student Student;

void print_data(Student *ps);

int main(void)
{
    Student s1 = { 315, 4.2 };

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1f\n", ps -> grade);
}

------typedef를 사용한 형 재정의의 다른 형식 사용------

enum student {num, grade};

int main(void)
{
    enum student st;
    
}

------문제 풀기------
struct student
{
    int num;
    char name[20];
    int kor;
    int eng;
    int math;
    int sum;
    double avg;
    char grade;

};
typedef struct student Student;

void print_data(Student *ps);
void input_data(Student *ps);
void process_data(Student *ps);




int main(void)
{
    
    struct student s1[5] = {
        {315, "홍길동"},
        {316, "이순신"},
        {317, "서하윤"},
        {318, "유관순"},
        {319, "박신혜"}
    };

    input_data(s1);
    process_data(s1);
    print_data(s1);


    return 0;
}



void input_data(Student *ps)
{
    for (int i = 0; i < 5; i++)
    {
        printf("학번 : %d\n", ps[i].num);
        printf("이름 : %s\n", ps[i].name);
        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &ps[i].kor, &ps[i].eng, &ps[i].math);
    }

    
}

void process_data(Student *ps)
{
    for (i = 0; i < 5; i++)
    {
        ps[i].sum = ps[i].kor + ps[i].eng + ps[i].math;
        ps[i].avg = ps[i].sum / 3.0;
    }

    if (ps[i].avg >= 90.0)
}

------파일을 열고 닫는 프로그램------
int main(void)
{
    FILE *fp;

    char str[] = "hannaindae";
    int i;

    fp = fopen("a.txt", "a");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}

------로그를 이용한 프로그램------*/
int main(void)
{

    FILE *fp;
    char buffer[1024];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    fp = fopen("log.txt", "r");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) 
    {
        // 4. 읽어온 한 줄(buffer) 안에 "ERROR" 문자열이 있는지 검색
        //    strstr(검색할_문자열, 찾을_단어)
        if (strstr(buffer, "ERROR") != NULL) 
        {
            // "ERROR"가 포함되어 있으면 카운트 증가
            count1++;
        }
        else if (strstr(buffer, "WARNING") != NULL) 
        {
            count2++;
        }
        else if (strstr(buffer, "INFO") != NULL) 
        {
            count3++;
        }
    }
    fclose(fp);

    printf("ERROR가 %d개 있습니다.\n", count1);
    printf("INFO가 %d개 있습니다.\n", count2);
    printf("WARNING이 %d개 있습니다.\n", count3);

    return 0;
}
