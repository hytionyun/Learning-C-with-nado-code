#include <stdio.h>

int main(void)  
{
    /*
    char c = 'A';
    printf("%c\n", c);
    */

    char str[256];
    scanf("%s", str);
    /*
    // 윈도우 에서는 
    scanf_s("%s", str, (unsigned int) sizeof(str)); //혹은
    scanf_s("%s", str, 256); //문자형 변수 크기 직접 입력
    */
    printf("%s\n", str);
    return 0;
}