//랜덤 상자에서 나오는 고양이 .. 서로 다른 고양이 5종 입양하기
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
    char *character;
    int level; //(1-5). 레벨 높을 수록 키우기 어려움
} CAT;

CAT cats[5]; //고양이 전체 목록 : 구조체 배열로 선언
int collection[5] = {0, 0, 0, 0, 0}; //입양한 고양이 담을 배열 ( 0==없음, 1==있음 )

void initCats(); //고양이 초기화
void printCat(int catNum);
int checkCollection(); //고양이 5마리 다 입양했는지 확인하는 함수

int main(void){
    srand(time(NULL)); //입양할 고양이 번호 랜덤 생성
    initCats();

    while(1){
    printf("\nENTER 누를 시 고양이가 뿅 하고 나와요\n");
    getchar(); //ENTER 입력받기. 반환값 무시되었다는 경고 메세지 나오면 (void) 앞에 붙여주기
    int selected = rand() % 5; 

    printCat(selected); //어떤 고양이가 나왔는지 알려주는 함수
    collection[selected] = 1; //고양이를 입양 상자에 넣었다고 표시
    int collectAll = checkCollection(); //고양이 5마리 다 모았는지 확인
    if(collectAll == 1){
        break;
    }
    }

    return 0;
}
void initCats(){
    cats[0].name = "돼냥이";
    cats[0].age = 5;
    cats[0].character = "귀여움";
    cats[0].level = 1;

    cats[1].name = "쿨쿨이";
    cats[1].age = 5;
    cats[1].character = "잠많이잠";
    cats[1].level = 1;

    cats[2].name = "쿨냥이";
    cats[2].age = 5;
    cats[2].character = "쿨함";
    cats[2].level = 2;

    cats[3].name = "번개냥이";
    cats[3].age = 5;
    cats[3].character = "빠름";
    cats[3].level = 3;

    cats[4].name = "냥아치";
    cats[4].age = 5;
    cats[4].character = "식탐많음";
    cats[4].level = 4;

}

void printCat(int catNum){
    printf("\n\n 와 ! 고양이의 집사가 되었어요 ! \n\n");
    printf("이름 : %s\n", cats[catNum].name);
    printf("나이 : %d\n", cats[catNum].age);
    printf("특징 : %s\n", cats[catNum].character);
    printf("레벨 : ");
    for (int i = 0; i < cats[catNum].level; i++){
        printf("%s", "⭐️");
    }
    printf("\n\n");
}

int checkCollection(){
    int collectAll = 1; // 상자에 모두 고양이가 있는지 표시, 모두 있음 상태로 초기화
    printf("\n\n보유한 고양이 목록이에요.\n\n");
    for (int i = 0; i<5; i++){
        if(collection[i] == 0){
            printf("%10s", "(빈 상자)");
            collectAll = 0; //고양이를 다 모으지 못한 상태
        } else {
            printf("%10s", cats[i].name);
        }
    }
    printf("\n\n==================\n\n");
    if (collectAll) {
        printf("\n\n축하합니다! 고양이 5마리를 모두 모았어요!\n\n");
    }
    return collectAll; //고양이 5마리 다 모으면 1
}
