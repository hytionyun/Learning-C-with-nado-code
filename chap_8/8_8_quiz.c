#include <stdio.h>
#include <stdlib.h>

int stuffArray[3][4]; //자판기에 저장된 상품
char * stuffLocate[13];

void initStuffArray(void);
void nameStuff(void);
void locateStuff(void);
int conv_x_pos(int x);
int conv_y_pos(int y);
void printStuff(void);
void questionStuff(void);

int main(void)
{   
    initStuffArray();
    nameStuff();
    locateStuff();
    printStuff();
    questionStuff();
    return 0;
}

void initStuffArray(void){
    for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stuffArray[i][j] = -1 ;
		}
	}
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
			printf("%d. %-12s", stuffArray[i][j]+1, stuffLocate[stuffArray[i][j]]);
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