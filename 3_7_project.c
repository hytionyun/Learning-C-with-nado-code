#include <stdio.h>

int main(void)  
{   
    int floor;
    printf("몇 층으로 쌓겠습니까? (5~100) ");
    scanf("%d", &floor);

    for (int i = 0; i < floor; i++){
        for (int j = 0; j < floor-i-1 ; j++){
            printf(" ");
        };
        for (int k = 0; k <= i*2  ; k++){
            printf("*");
        };
        printf("\n");
    };
    return 0;
}