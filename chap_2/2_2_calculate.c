#include <stdio.h>
#include <math.h> //pow(), sqrt() 함수가 정의된 헤더파일

int main(void)  
{   
    // int add = 3 + 7;
    // printf("3 + 7 = %d\n", add);
    printf("%d + %d = %d\n", 3, 7, 3 + 7);
    printf("%d - %d = %d\n", 3, 7, 3 - 7);
    printf("%d * %d = %d\n", 3, 7, 3 * 7);
    printf("%d / %d = %d\n", 10, 2, 10 / 2);
    printf("%d ^ %d = %.0f\n", 10, 2, pow(10, 2));
    printf("%d 의 제곱근 = %.0f\n", 9, sqrt(9));


    return 0;
}