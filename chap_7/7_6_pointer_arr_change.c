#include <stdio.h>

void changeArray(int *ptr); //배열의 주소를 전달받아 함수 내에서 배열의 값을 바꿈.
int main(void){
    int arr2[3] = {10, 20, 30};
    changeArray(arr2); //배열의 시작 주소는 배열의 이름 (==&arr2[0])
    for (int i = 0; i < 3; i++){
        printf("%d\n", arr2[i]);
    }
    return 0;
}
void changeArray(int *ptr){
    ptr[2] = 50;
}