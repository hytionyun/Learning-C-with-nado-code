#include <stdio.h>

int main(void)  
{
    for(int i = 1; i<= 5; i++){ // 5층
        for(int j = 1; j<= i; j++){ //한 층에 i개씩 쌓자
        printf("*");
        };
        printf("\n");
    };
    return 0;
}