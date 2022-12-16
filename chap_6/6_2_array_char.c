#include <stdio.h>

int main (void){
    char c ='Q'; //문자는 작은 따옴표로 선언
    printf("%c\n", c);

    char str[7] ="coding"; //문자열은 큰 따옴표로 선언, 문자열의 끝을 알리는 널 문자(\0)들어갈 공간 마련해야함(글자수+1)
    printf("배열의 값 : %s, 배열의 크기 : %lu\n", str, sizeof(str)); //sizeof연산자 : 배열, 변수 자료형 등이 메모리 얼마나 차지하는지 바이트 단위로 알려줌, 알파벳과 숫자는 1바이트 차지함.
    for (int i = 0; i < sizeof(str); i++){
        printf("%c\n", str[i]); //마지막에 널 문자가 출력됨
    }

    char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '\0'};
    char d_array[9] = {'c', 'o', 'd', 'i', 'n', 'g', '\0'};
    printf("%s\n", c_array); //coding
    printf("%s\n", d_array); //coding (나머지는 널 문자로 채워짐)
    //이를 아스키 코드(문자, 기호를 0과 1의 신호로 변환한 것)으로 바꿔 출력해 보면 ...
    for (int i = 0; i < sizeof(d_array); i++){
        printf("%d\n", d_array[i]); //널 문자의 아스키코드는 0임.
    }

    char kor[] = "나도코딩";
    printf("배열의 값 : %s, 배열의 크기 : %lu\n", kor, sizeof(kor)); //한글은 한 글자당 2바이트 차지

    return 0;
}