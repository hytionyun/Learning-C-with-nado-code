#include <stdio.h>

int main(void){
    int amy = 1;
    int renal = 2;
    int walo = 3;
    int shel = 4;
    printf("shel네 주소 : %p. 원래 암호 : %d\n", &shel, shel);

    int * missionMan = &shel; //포인터 변수 선언, 변수의 주소를 알아낼 수 있다.
    *missionMan = *missionMan * 3;
    printf("미션맨이 방문한 곳 : %p, 암호 : %d\n", missionMan, *missionMan);

    int * spy = missionMan; //스파이는 미션맨이 알아낸 집 주소를 알 수 있음.
    *spy = *spy - 1;
    printf("스파이가 방문한 곳 : %p, 암호 : %d\n", missionMan, *missionMan);

    printf("미션맨의 주소 : %p\n", &missionMan);
    printf("스파이의 주소 : %p\n", &spy);
    return 0;
}

/*포인터 변수 2개가 같은 주소(하나의 메모리 공간)을 가리킬 수 있다.*/
/*포인터 변수로 주소를 알고 있으면 해당 주소에 저장된 값을 읽을 수도, 변경할 수도 있다.*/

/*정리 : 미션맨, 스파이 같은 포인터 변수는 어떤 변수의 주소를 값으로 가져서 주소를 이용해 주소에 해당하는 변수의 값을 직접 바꿀 수 있다.*/
/*정리 : %p &missionMan : 미션맨의 주소 , %p missionMan : 미션맨이 가리키는 주소, %d *missionMan : 가리키는 주소의 암호 */