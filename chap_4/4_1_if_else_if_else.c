#include <stdio.h>

int main(void)  
{   
    int age;
    printf("당신의 나이는 몇 살인가요?\n");
    scanf("%d", &age);
    if (age>=8 && age<=13){ //AND 연산자
        printf("초등학생입니다.\n");
    } else if (age>=14 && age<=16){
        printf("중학생입니다.\n");
    } else if (age>=17 && age<=19){
        printf("고등학생입니다.\n");
    }
    return 0;
}