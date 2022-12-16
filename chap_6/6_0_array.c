#include <stdio.h>

int main(void){
    int subway_array[3]; //정수형 변수 3개 선언과 같은 역할
    subway_array[0] = 30; //배열 선언 [30][][], 배열 크기는 항상 상수로 선언.
    subway_array[1] = 40;
    subway_array[2] = 50;
    for (int i = 0; i < 3; i++){
        printf("%d번째 인덱스에 들어있는 값 : %d\n", i, subway_array[i]);
        printf("%d번째 호차에 들어있는 사람 수 : %d명\n", i+1, subway_array[i]);
    }
    return 0;
}