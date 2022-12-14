#include <stdio.h>

int main(void)  
{   
    int age;
    printf("당신의 나이는 몇 살인가요?\n");
    scanf("%d", &age);
    if(age>=20){
        printf("성년입니다.\n");
    }else{
        printf("청소년입니다.\n");
    }
    return 0;
}