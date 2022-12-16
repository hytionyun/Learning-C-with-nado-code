#include <stdio.h>

int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div_moc(int num1, int num2);
int div_na(int num1, int num2);
void p(int total);


int main(void){
    int x, y;
    printf("정수 두 자리를 입력해주십시오 : ");
    scanf("%d %d", &x, &y);

    add(x, y);
    sub(x, y);
    mul(x, y);
    div_moc(x, y);
    div_na(x, y);
    return 0;
}

int add(int num1, int num2){ 
    int total;
    total = num1 + num2;
    printf("더하기 결과 : ");
    p(total);
    return total;
     }
int sub(int num1, int num2){
    int total;
    total = num1 - num2;
    printf("빼기 결과 : ");
    p(total);
    return total;
}
int mul(int num1, int num2){
    int total;
    total = num1 * num2;
    printf("곱하기 결과 : ");
    p(total);
    return total;
}
int div_moc(int num1, int num2){
    int total;
    total = num1 / num2;
    printf("나누기 결과(몫은) : ");
    p(total);
    return total;
}
int div_na(int num1, int num2){
    int total;
    total = num1 % num2;
    printf("나누기 결과(나머지는) : ");
    p(total);
    return total;
}
void p(int total){
    printf("%d 입니다. \n", total);
}