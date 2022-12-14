#include <stdio.h>

int main(void)  
{
    /*
    int input;
    printf("값을 입력하세요 : ");
    scanf("%d", &input);
    //mac에서는 scanf_s가 인식이 되지 않는다. 윈도우에선 scanf_s 인식 가능.
    printf("입력값 : %d\n", input);
    return 0;
    */

   int one, two, three;
   printf("정수 세 개를 입력하세요 : ");
   scanf("%d %d %d", &one, &two, &three);
   printf("첫 번째 값 : %d\n", one);
   printf("두 번째 값 : %d\n", two);
   printf("세 번째 값 : %d\n", three);
   return 0;
}