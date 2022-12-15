#include <stdio.h>

int main(void) 
{   
    int age;
    printf("당신의 나이는 몇 살인가요?\n");
    scanf("%d", &age);

    switch(age){
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            printf("초등학생입니다.\n");
            break;
        case 14:
        case 15: //만약 값이 15이면 14까지 지나치다가 15에서 아무것도 수행하지 않은채 break 전까지 수행
        case 16:
            printf("중학생입니다.\n");
            break;
        case 17:
        case 18:
        case 19:
            printf("고등학생입니다.\n");    
            break;
        default:
            printf("청소년이 아닙니다.\n");    
    }
    // if (age>=8 && age<=13){ //AND 연산자
    //     printf("초등학생입니다.\n");
    // } else if (age>=14 && age<=16){
    //     printf("중학생입니다.\n");
    // } else if (age>=17 && age<=19){
    //     printf("고등학생입니다.\n");
    // } else {
    //     printf("청소년이 아닙니다.\n");
    // }
    // return 0;
}