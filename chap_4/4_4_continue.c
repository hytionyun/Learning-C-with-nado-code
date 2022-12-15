#include <stdio.h>

int main(void)  
{
    for (int i = 1; i <= 30; i++){
        if (i >= 6 && i <=10){
            if (i == 7){            
                printf("%d번 학생은 결석입니다. \n", i);
                continue;  //이번 반복만 종료, 다음 반복으로 넘어감
                }
            printf("%d 번 학생은 조별 발표 준비를 하세요. \n", i);
        }
    };
    return 0;
}