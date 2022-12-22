#include <stdio.h>
#define ADD(num1, num2) (num1 + num2) //값을 두개 입력받아 서로 더하는 매크로 함수
//전처리기에 의해 단순 치환되는 방식, 속도 빠름
int main(void){
    int result = ADD(10, 20);
    printf("%d\n", result);
    return 0;
}