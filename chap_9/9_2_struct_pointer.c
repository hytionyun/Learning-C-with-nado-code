#include <stdio.h>

struct GameInfo //전역위치에 구조체 정의
{
    //GameInfo 구조체의 멤버
    char * name; 
    int year;
    int price;
    char * company;  
};

int main (void){
	struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2022;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";

    struct GameInfo * gamePtr; //구조체 포인터 변수 선언
    gamePtr = &gameInfo1; //앞에서 선언한 구조체 변수 gameInfo1의 주소 가져오기
    //gamePtr은 구조체 변수 gameInfo1의 주소를 담은 구조체 포인터가 됨.
    printf("-- 미션맨의 게임 출시 정보 --\n");
    printf("게임 이름 : %s\n", (*gamePtr).name); //gamePtr은 int형 변수의 주소를 담고 있는데 앞에 *을 붙여서 주소에 저장된 값 나타냄
    //printf("게임 이름 : %s\n", gamePtr->name); //위와 같은 의미다
    printf("게임 출시 년도 : %d\n", (*gamePtr).year); //괄호 안할 시 gameInfo1.year의 주소에 담긴 값을 불러오게 됨 (원하는 건 gameInfo의 주소에 담긴 값 중 year의 값인데 주소를 잘못 찾아가게됨)
    printf("게임 가격 : %d\n", (*gamePtr).price);
    printf("제작 회사 : %s\n", (*gamePtr).company);

	return 0;
}