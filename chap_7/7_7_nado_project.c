#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int level;
int arrayFish[6]; //어항의 물  높이
int* cursor; //배열의 값에 접근하기 위해 포인터 변수 사용

void initData(void);
void printfFishes(void);
void decreaseWater(long elapsedTime);
int checkFishAlive(void);

int main(void)
{
    struct timeval start; // 게임 시작 시간, 함수의 실행시간을 측정
    struct timeval curr; // 현재 시간
    
    long totalElapsedTime = 0; // 총 경과 시간
    long prevElapsedTime = 0; // 물을 준 시간 간격 측정
    int num; // 물을 줄 어항 번호
    initData(); // 게임 초기화 함수 호출

    cursor = arrayFish; // cursor[0], cursor[1], ...

    gettimeofday(&start, NULL); // 현재 시간을 시작 시간으로 저장
    while (1)
    {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요? ");
        scanf("%d", &num);

        // 입력값 체크
        if (num < 1 || num > 6)
        {
            printf("\n입력값이 잘못되었습니다\n");
            continue; //이번 반복 종료, 다음 반복으로 넘어감
        }
        
        // 총 경과 시간
        gettimeofday(&curr, NULL);
        totalElapsedTime = curr.tv_sec + (curr.tv_usec / CLOCKS_PER_SEC)
            - start.tv_sec - (start.tv_usec / CLOCKS_PER_SEC); // 총 경과 시간을 초단위로 표시 , start.tv_sec, curr.tv_usec 은 초
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        // 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간 : 물이 얼마나 증발했는지 알기 위함
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);
        decreaseWater(prevElapsedTime); // 어항의 물을 감소(증발)시키는 함수 호출

        // 사용자가 입력한 어항에 물 주기 (조건 2개 존재)
        // 1. 어항의 물 높이가 0 이하면 물을 주지 않음
        if (cursor[num - 1] <= 0)
        {
            printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다\n", num);
        }
        // 2. 어항의 물 높이가 0 초과면 100을 넘지 않는지 확인하고 물을 줌
        else if (cursor[num - 1] + 1 <= 100)
        {
            // 물을 준다
            printf("%d 번 어항에 물을 줍니다\n\n", num);
            cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
        }

        // 레벨업 확인(레벨업은 20초마다 한 번씩 수행)
        if (totalElapsedTime / 20 > level - 1) //총 시간을 20초로 나눴을때의 몫은 현재 레벨과 같음. (20초/20=1, 1-1=0, 따라서 1렙 업!/// 15초/20 = 0, 0-1 = -1, 따라서 렙업안함!)
        {
            // 레벨업
            level++; // level : 1 -> level : 2 -> level : 3...
            printf("*** 축하합니다. %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);
            if (level == 5) // 최고 레벨
            {
                printf("\n\n축하합니다. 최고 레벨을 달성했습니다. 게임을 종료합니다\n\n"); // 1) 게임 종료 조건(택1) 중 1. 5레벨 달성
                exit(0); //뒤에 어떤 문장이 오든 프로그램 종료. <stdlib.h> 파일에 포함되어 있는 함수.
            }
        }

        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0)
        {
            // 물고기가 모두 죽음
            printf("모든 물고기가 죽었습니다. ㅠㅠ \n");
            exit(0); //게임 종료
        }
        else
        {
            // 물고기가 최소 한 마리 이상 살아 있음
            printf("물고기가 아직 살아 있어요!\n");
        }
        prevElapsedTime = totalElapsedTime; //다음 반복에 활용(직전에 물을 준 시간정보를 추후 활용하기 위해 1회차 totaltime을 저장)
    }
    return 0;
}

void initData(void) //전역변수 초기화
{
    level = 1; // 게임 레벨 (1~5)
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; // 어항의 물 높이 (0~100)
    }
}

void printfFishes(void) // 물 줄 때마다 물 높이 출력해 보여주기
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("  %3d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime) //직전 물 준 시간을 이용해 증발한 물의 양을 계산하고 어항의 물 높이 줄이기
{
    for (int i = 0; i < 6; i++)
    {   
        /* 난이도 조절 방법 : 숫자 3 조절 */
        arrayFish[i] -= (level * 3 * (int)elapsedTime); //long을 int로 형변환 필요, 물 높이와 직전 물 준시간, 레벨, 난이도는 비례관계
        if (arrayFish[i] < 0) //물높이가 음수이면
        {
            arrayFish[i] = 0; //0으로 저장 후 다음 어항으로 넘어감
        }
    }
}

int checkFishAlive(void) // 2) 게임 종료 조건(택1) 중 2. 5레벨 달성 전 모든 물고기 죽음
{ //모든 물고기 죽었는지 확인하는 함수
    for (int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0)
            return 1; // 참 True
    }
    return 0; //if문 실행 못하면(모든 물고기 죽으면) 0 반환
}

/* 이 프로그램의 동작 포인트 : 6개 공간을 가진 배열을 포인터 변수인 cusor로 접근하여 어항의 물 높이를 바꿔준다. */