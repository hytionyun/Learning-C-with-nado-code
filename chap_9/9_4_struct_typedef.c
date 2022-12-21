//구조체 별명 붙이기 1탄
#include <stdio.h>

struct GameInfo
{
    char * name; 
    int year;
    int price;
    char * company; 
    struct GameInfo * friendGame;
};

int main (void){
    typedef struct GameInfo 게임정보; //typedef를 이용해 구조체(struct GameInfo)에 별명(게임정보) 붙이기
    게임정보 game1; //구조체 변수 선언
    game1.name = "한글 게임"; //구조체 멤버에 값 저장
    game1.year = 2022;
    printf("게임 이름: %s\n", game1.name);
    printf("발매 년도: %d\n", game1.year);
    return 0;
}