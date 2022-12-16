#include <stdio.h>

int main(void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //배열명[배열 크기 n] = {요소(0~ n-1, 배열명[인덱스]로 구분해줌)}
    for (int i = 0; i < 10; i++){
        printf("%d번째 인덱스의 값 : %d\n", i, arr[i]);
    }

    float arr_f[5] = {1.0f, 2.0f, 3.0f};
    for (int i = 0; i < 5; i++){
        printf("%d번째 인덱스의 값 : %.2f\n", i, arr_f[i]);
    }
    return 0;
}