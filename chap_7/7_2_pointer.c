#include <stdio.h>

int main(void){
    int amy = 1;
    int renal = 2;
    int walo = 3;
    int shel = 4;
    int * missionMan = &shel; //포인터 변수 선언, 변수의 주소를 알아낼 수 있다.
    *missionMan = *missionMan * 3;
    printf("shel네 주소 : %p. 암호 : %d\n", &shel, shel);
    printf("미션맨이 방문한 곳 : %p, 암호 : %d\n", missionMan, *missionMan);

    return 0;
}

/*즉, 포인터 변수는 다른 변수의 주소를 알아낼 수 있으며 이 주소에 찾아가 값도 직접 바꿀 수 있다.*/