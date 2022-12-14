#include <stdio.h>

int main(void){
    for (int i = 1; i<=10; i++){
        printf("for loop : Hello World %d\n", i);
    };

    int x = 1;
    while(x <= 10){
        printf("while loop : Hello World %d\n", x); //x++
        ++x; //x++
    };

    int y = 1;
    do{
        printf("do-while loop : Hello World %d\n", y);
        y++;
    }while(y<=10);
    return 0;
}