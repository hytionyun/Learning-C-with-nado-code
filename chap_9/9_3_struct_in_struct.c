#include <stdio.h>

struct GameInfo //전역위치에 구조체 정의
{
    //GameInfo 구조체의 멤버
    char * name; 
    int year;
    int price;
    char * company; 
    struct GameInfo * friendGame; // 구조체 포인터 : 구조체 GameInfo의 구조체 변수
};

int main (void){
	struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2022;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";
    struct GameInfo gameInfo2 = {"너도게임", 2022, 100, "너도회사"};  //구조체 변수 한꺼번에 초기화
    gameInfo1.friendGame = &gameInfo2; //gameInfo2 회사의 게임 정보를 담은 구조체 변수의 주소 저장

    //구조체 멤버 출력
    printf("\n--다른 회사의 게임 출시 정보--\n");
    printf("게임 이름 : %s\n", gameInfo1.friendGame->name);
    printf("게임 출시 년도 : %d\n", gameInfo1.friendGame->year);
    printf("게임 가격 : %d\n", gameInfo1.friendGame->price);
    printf("제작 회사 : %s\n", gameInfo1.friendGame->company);

	return 0;
}
