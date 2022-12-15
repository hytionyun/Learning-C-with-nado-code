#include <stdio.h>
#include <string.h>

int main(void) {

    printf("\n* '코 딩 커 피 숍' 메뉴판 *\n");
    printf("커피 1 잔 : 4,500원\n");
    printf("샌드위치 1 개 : 6,000원\n");
    printf("샌드위치 구매 시 커피 가격 할인, 1잔 당 : 3,500원 (수량 제한 없음)\n\n");

    int cost = 0, coffee = 0, sandwich = 0;
    
    printf("주문할 메뉴의 수량을 입력해 주세요.");
    printf("\n커피 : ");
    scanf("%d", &coffee);
    printf("샌드위치 : ");
    scanf("%d", &sandwich);
    
    if (sandwich > 0){
        cost = coffee*3500 + sandwich*6000;
    } else if (sandwich == 0){
        cost = coffee*4500;
    } else {
        printf("오류!");

    }
    printf("최종 금액은 %d원 입니다.\n", cost);

    return 0;
}