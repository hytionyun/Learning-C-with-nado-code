#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int score[5] = {rand() % 101, rand() % 101, rand() % 101, rand() % 101, rand() % 101};
    for(int j = 0; j < 5; j++){
    printf("score is ... %d\n", score[j]);
    }
    int total = 0;
    float exact = 0.0f;
    for (int i = 0; i < 5; i++){
        total += score[i];
        exact = total / 5.0f;
    }
    printf("total is ... %d, exact is ... %.1f\n", total, exact);
    return 0;
}