#include <stdio.h>
int main(void){
    int a = 10;
    printf("a는 %d\n", a);
    a++;
    printf("a는 %d\n", a);
    a++;
    printf("a는 %d\n", a);

    int b = 20;
    printf("b는 %d\n", ++b); //증가 연산 수행 후 출력 작업 수행
    printf("b는 %d\n", b++); //출력 작업 수행 후 다음 줄로 넘어가기 전에 증가 연산 수행
    printf("b는 %d\n", b);
    printf("b는 %d\n", --b);

    int c = 7;
    printf("b/c의 나머지 %d\n", c%b);
    return 0;


}