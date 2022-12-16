#include <stdio.h>

int function_with_params_return(int a, int b, int c); //a, b, c is parameter(매개변수)

int main(void){
    int ret;
    ret = function_with_params_return(1, 2, 3); //1, 2, 3 is argument(인수)
    printf("반환값은 %d\n", ret);
    return 0;
}

int function_with_params_return(int a, int b, int c){
    printf("전달값과 반환값이 있는 함수입니다. 전달값은 %d %d %d\n", a, b, c);
    return a + b + c;
}