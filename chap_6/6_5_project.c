#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int treatment = rand() % 4; // 0~ 3 중 진짜 발모제 선택
    printf("\n\n게임 시작, 발모제를 찾아라!\n\n");

    int cntShowBottle = 0; //이번 회차에 조합할 약병 개수
    int prevCntShowBottle =0; //앞 회차에 조합했던 약병 개수

    for (int i = 1; i <= 3; i++){ //총 3판
        int bottle[4] = {0, 0, 0, 0}; //약병 총 4개, 초기화
        
        /*테스트마다 약병을 몇개 조합할까?*/
        //정답률 높이기 : 앞 회차에 조합한 약병 개수와 이번 회차에 조합할 약병 개수 달라지도록설정
        do{
            cntShowBottle = rand() % 2 + 2; //약병 2~ 3개 조합

        }while(cntShowBottle == prevCntShowBottle); //두 값이 같으면 다시 조합
        prevCntShowBottle = cntShowBottle;
        printf("\n %d 번째 테스트 : \n", i);

        /*조합할 약 병 번호는?*/
        int isIncluded = 0; //진짜 발모제인지 확인용
        for (int j = 0; j < cntShowBottle; j++){
            int randBottle = rand() % 4;  //약병 번호 뽑기
            if (bottle[randBottle] == 0){ //선택되지 않은 약병일 경우
                bottle[randBottle] = 1;
                if(randBottle == treatment){ //진짜 발모제와 같을 경우
                    isIncluded = 1;
                }
            } else { //1차선택때 이미 선택된 약병일 경우(중복방지)
                j--;
            }
        }

        /*조합 결과*/
        for (int k = 0; k < 4; k++){
            if (bottle[k] == 1){
                printf("%d ", k+1);
            }
            }
            printf("번 물약을 머리에 바릅니다.\n");
            if (isIncluded == 1){
                printf("성공! 머리카락이 났어요!\n");
            } else {
                printf("실패! 머리카락이 나지 않았어요 ㅠㅠ\n");
            }
            printf("계속하려면 Enter를 누르세요. \n");

            getchar(); //Enter를 입력받아 다음 테스트 회차로 넘어가기

    }
        // 사용자 입력
        printf("\n\n 발모제는 몇 번일까요?");
        int answer;
        scanf("%d", &answer);
        if (answer == treatment + 1) {//진짜 발모제 번호와 같다면 
            printf("정답입니다!\n");
        } else{
            printf("땡! 틀렸어요. 정답은 %d번 입니다.\n", treatment+1);
        }
    
    return 0;
}