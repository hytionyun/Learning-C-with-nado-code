#include <stdio.h>

int main(void){
    int amy = 1;
    int renal = 2;
    int walo = 3;
    int shel = 4;
    int * missionMan = &shel; //포인터 변수 선언, 변수의 주소를 알아낼 수 있다.

    printf("shel네 주소 : %p. 암호 : %d\n", &shel, shel);
    printf("미션맨이 방문한 곳 : %p, 암호 : %d\n", missionMan, *missionMan);

    return 0;
}