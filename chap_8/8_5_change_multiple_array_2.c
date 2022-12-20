#include <stdio.h>

int main(void){
    int arr4[3][3][3] = {
        {
            {1, 2, 3},
            {3, 4, 5},
            {5, 6, 7}
        },
        {
            {11, 12, 13},
            {13, 14, 15},
            {15, 16, 17}
        },
        {
            {21, 22, 23},
            {23, 24, 25},
            {25, 26, 27}
        }
    };
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                printf("3차원 배열 [%d][%d][%d]의 값 : %d\n", k, i, j, arr4[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}