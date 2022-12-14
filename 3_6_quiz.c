#include <stdio.h>

int main(void)  
{   
    for (int i = 5; i < 8; i++){
        printf("%d단 출력\n", i);
        for (int j = 3; j <6; j++){
            printf("%d x %d = %d\n", i, j, i * j);
        }
    printf("\n");
    }
    return 0;
}