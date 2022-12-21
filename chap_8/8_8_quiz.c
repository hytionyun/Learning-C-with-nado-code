#include <stdio.h>
#include <stdlib.h>

int stuffArray[3][4]; //자판기에 저장된 상품지도, 전역변수로 선언된 배열은 초기화 필요 없음
char * stuffLocate[13]; //상품 이름 12개를 메모리 공간에 저장(%12s, *stuffLocate[0]), 포인터 배열엔 시작 주소 저장(%p, stuffLocate[0])

void nameStuff(void); //stuffLocate의 인덱스에  상품 이름 나타내는 번호 저장
void locateStuff(void); //상품 지도의 좌표 -> 상품 번호로 변환
int conv_x_pos(int x); // 0/4 == 0, 0%4 == 0 ... 11/4 == 2, 11%4 == 3
int conv_y_pos(int y);
void printStuff(void); //좌표->값으로 변환된 stuffArray를 이용해 '상품 번호. 이름' 출력
void questionStuff(void); //상품 구매 및 오류처리 부분

int main(void)
{   
    nameStuff();
    locateStuff();
    printStuff();
    questionStuff();
    return 0;
}

void nameStuff(void)
{
    stuffLocate[0] = "우유";
    stuffLocate[1] = "커피";
    stuffLocate[2] = "주스";
    stuffLocate[3] = "탄산음료";
    stuffLocate[4] = "칸칩";
    stuffLocate[5] = "거북칩";
    stuffLocate[6] = "감자칩";
    stuffLocate[7] = "고구마칩";
    stuffLocate[8] = "안타볼";
    stuffLocate[9] = "초코링";
    stuffLocate[10] = "가재깡";
    stuffLocate[11] = "씨리얼";
}

void locateStuff(void)
{
    for (int i = 0; i < 12; i++)
    {
        int x = conv_x_pos(i);
        int y = conv_y_pos(i);
        stuffArray[x][y] = i;
    }
}

int conv_x_pos(int x)
{
    return x / 4;
}

int conv_y_pos(int y)
{
    return y % 4;
}

void printStuff(void)
{
    printf("\n===============자판기 메뉴 목록================\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d. %-12s", stuffArray[i][j]+1, stuffLocate[stuffArray[i][j]]); //좌표->값으로 변환된 stuffArray를 이용해 '상품 번호. 이름' 출력
		}
		printf("\n");
	}
	printf("==============================================\n");
}

void questionStuff(void)
{   
    int pickNum = 0;
    printf("\n===============몇번 상품을 주문하시겠습니까?================\n");
    printf("입력(1~12) : ");
    scanf("%d", &pickNum);
    if (pickNum > 12 || pickNum < 1)
    {
        printf("입력받은 번호는 유효하지 않은 번호 입니다.\n");
        exit(0);
    }
    else
    {
    printf("구매하신 상품은 %d. %s 입니다.\n", pickNum, stuffLocate[pickNum]);
    }
}