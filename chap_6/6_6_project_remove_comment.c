#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int realBottle = rand() % 4; //0~3
    printf("\n\n게임 시작, 발모제를 찾아라!\n\n");

    int cntBottle = 0; 
    int prevBottle =0; 

    for (int i = 1; i <= 3; i++){ 
        int allBottle[4] = {0, 0, 0, 0};
        do{
            cntBottle = rand() % 2 + 2; //2~3

        }while(cntBottle == prevBottle); 
        prevBottle = cntBottle;
        printf("\n %d 번째 테스트 : \n", i);

        int isReal = 0; 
        for (int j = 0; j < cntBottle; j++){
            int pickedBottle = rand() % 4;  //0~3
            if (allBottle[pickedBottle] == 0){ 
                allBottle[pickedBottle] = 1;
                if(pickedBottle == realBottle){ 
                    isReal = 1;
                }
            } else { 
                j--;
            }
        }


        for (int k = 0; k < 4; k++){
            if (allBottle[k] == 1){
                printf("%d ", k+1);
            }
            }
            printf("번 물약을 머리에 바릅니다.\n");
            if (isReal == 1){
                printf("성공! 머리카락이 났어요!\n");
            } else {
                printf("실패! 머리카락이 나지 않았어요 ㅠㅠ\n");
            }
            printf("계속하려면 Enter를 누르세요. \n");

            getchar(); 

    }
        
        printf("\n\n 발모제는 몇 번일까요?");
        int answer;
        scanf("%d", &answer);
        if (answer == realBottle + 1) {
            printf("정답입니다!\n");
        } else{
            printf("땡! 틀렸어요. 정답은 %d번 입니다.\n", realBottle+1);
        }
    
    return 0;
}