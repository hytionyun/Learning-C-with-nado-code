#include <stdio.h>

//1. 함수 선언 : 이런 함수를 쓸거야
void p(int num); // 반환형 함수명(전달값);
/*반환형이 void일 경우 아무것도 반환하지 않겠다.*/

int main (void){
    int num = 2;
    //3. 함수 호출 : p라는 함수를 호출해서 num값을 넘길거야
    p(num);
    num += 3;
    p(num);
    num -= 1;
    p(num);
    num *= 3;
    p(num);
    num /= 6;
    p(num);
    return 0;
}

//2. 함수 정의 : 이 함수는 어떤 일을 해
void p(int num){
    printf("num is ..%d \n", num);
}

/* 함수 사용 이유?
1. 코드 중복 방지, 효율적인 프로그래밍(일일이 찾아 수정할 필요X)
2. 다른 프로젝트에서 재사용 가능*/