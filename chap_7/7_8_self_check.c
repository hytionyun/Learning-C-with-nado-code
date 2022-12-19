#include <stdio.h>
// #include <math.h>

void square(int *num);
int main(void){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++){
        square(&arr[i]);
    }
    for (int i = 0; i < 10; i++){
        printf("%d",arr[i]);
        if (i+1 < 10){ //다음 요소가 남아있는 경우에만 쉼표 (,) 출력
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}
void square(int *num){
    if (*num % 2 == 0){
        *num = (*num) * (*num);
    }
}

// 나의 답
// void square(int *num);
// int main(void){
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i = 0; i < 10; i++){
//         square(&arr[i]); //메모리 주소를 전달해야 함
//     }
//     return 0;
// }
// void square(int *num){
//     if (*num % 2 == 1){
//         printf("%d \n", *num);
//     } else {
//         *num = pow(*num, 2);
//         printf("%d\n", *num);
//     }
// }