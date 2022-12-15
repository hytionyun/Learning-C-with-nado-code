#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    //난수 생성 (1~100)
    srand(time(NULL));
    int num = rand() % 100+1;

    //정답
    // printf("정답 : %d\n", num);

    //사용자 입력 값
    int answer = 0; //처음엔 없으니 초기화

    //맞힐 기회
    int chance = 5;
    printf("\n숫자 게임에 오신 것을 환영합니다. 1~100의 숫자 중 하나를 입력하세요. \n");
    while(1){
        printf("\n%d번의 기회가 남았습니다. \n", chance);
        chance-=1;
        if (chance == 0){
            printf("마지막 기회에요! \n");
        }
        printf("숫자 입력 : ");
        scanf("%d", &answer);
        if (num == answer){
            printf("정답입니다! \n");
            break;
        } else {
            if (num > answer){
                printf("UP\n");
            }
            else if(num < answer){
                printf("DOWN\n");
            }
            else {
                printf("오류 발생! \n");
                break;
            }
        }
        if (chance == 0){
            printf("\n아쉽게도 기회를 다 써버렸네요, \n");
            printf("정답은 %d 입니다!\n", num);
            break;
        }
    }
    return 0;
}
