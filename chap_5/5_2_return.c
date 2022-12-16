#include <stdio.h>

int function_with_return();
void p(int num);

int main(void){
    int ret;
    ret = function_with_return();
    //int ret = function_with_return();
    p(ret);
    // printf("%d\n", ret);
    return 0;
}

int function_with_return(){
    printf("반환값이 있는 함수입니다.\n");
    return 10;
}

void p(int num){
    printf("num은 %d 입니다.\n", num);
}