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
    struct GameInfo gameArray[2] = {
        //구조체 변수 2개 초기화 시 2차원 배열 이용
        {"나도게임", 2022, 50, "나도회사"}, //gameArray[0] 
        {"너도게임", 2022, 100, "너도회사"} //gameArray[1] 
    };
    return 0;
}