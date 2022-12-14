#include <stdio.h>

int main(void)  
{
    char name[256], crime[256];
    int age;
    float weight; 
    double height; 
    
    printf("경찰 조서 제작을 위한 인적사항을 입력해주십시오.\n");
    printf("이름 : ");
    scanf("%s", name);
    //scanf_s("%s", name, sizeof(name)); //윈도우 버전
    printf("나이 : ");
    scanf("%d", &age);
    printf("몸무게 : ");
    scanf("%f", &weight);
    printf("신장 : ");
    scanf("%lf",&height);
    printf("범죄명 : ");
    scanf("%s", crime);
    //scanf_s("%s", crime, sizeof(crime));

    printf("경찰 조서가 제작되었습니다.\n");
    printf("이름 : %s\n", name);
    printf("나이 : %d\n", age); 
    printf("몸무게 : %.1f\n", weight);
    printf("신장 : %.1lf\n", height);
    printf("범죄명 : %s\n", crime);
    return 0;
}