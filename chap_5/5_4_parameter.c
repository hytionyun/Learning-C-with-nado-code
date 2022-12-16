#include <stdio.h>

void function_with_params(int a, int b, int c); //a, b, c is parameter(매개변수)

int main(void){
    function_with_params(1, 2, 3); //1, 2, 3 is argument(인수)
    return 0;
}

void function_with_params(int a, int b, int c){
    printf("전달값이 있는 함수입니다. 전달값은 %d %d %d\n", a, b, c);
}