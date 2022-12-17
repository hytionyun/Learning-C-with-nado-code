#include <stdio.h>

int level; //전역변수
int arrayFish[6];
void initData();

int main(void){
    initData();
    return 0;
}

void initData(){
    level = 1;
    for (int i = 0; i < 6; i++){
        arrayFish[i] = 100; //가득 찬 어항의 물높이
    }
}