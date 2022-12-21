//구조체 별명 붙이기 2탄
#include <stdio.h>

struct GameInfo
{
    char * name; 
    int year;
    int price;
    char * company; 
    struct GameInfo * friendGame;
};
typedef struct GameInformation //typedef struct까지만 써도 됨
{
    char * name; 
    int year;
    int price;
    char * company; 
    struct GameInfo * friendGame;
} GAME_INFO; //struct GameInformation을 GAME_INFO로 치환하겠다는 의미임

int main (void)
{
    GAME_INFO game2;
    game2.name = "한글 게임2";
    game2.year = 2023;
    printf("게임 이름: %s\n", game2.name);
    printf("발매 년도: %d\n", game2.year);
}