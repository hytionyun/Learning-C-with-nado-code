#include <stdio.h>

int main(void)  
{      
    /*
    //나의 코드
    char first_str[256];
    char second_str[256];
    scanf("%s %s", first_str, second_str);
    printf("%s %s\n", first_str, second_str);
    return 0;
    */

    //정답 코드
    char str1[256], str2[256];
    printf("첫 번째 문자열을 입력하세요 : ");
    scanf("%s", str1);
    printf("두 번째 문자열을 입력하세요 : ");
    scanf("%s", str2);
    printf("첫 번째 문자열 : %s\n", str1);
    printf("두 번째 문자열 : %s\n", str2);
    return 0;
}

