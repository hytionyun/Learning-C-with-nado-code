#include <stdio.h>
#include <time.h> //시간 관련 함수 모아 놓은 헤더파일
#include <stdlib.h> //난수 생성, 문자열 변화 함수 모아 놓은 헤더파일

int main(void) 
{
    srand(time(NULL)); //난수 초기화 후 난수 생성 가능
    rand() % 3; //0~2
    // rand() % 3+1; //1~3
    return 0;
}