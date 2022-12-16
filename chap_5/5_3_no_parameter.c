#include <stdio.h>

void function_without_params();

int main(void){
    function_without_params();
    return 0;
}

void function_without_params(){
    printf("전달값이 없는 함수입니다.");
}