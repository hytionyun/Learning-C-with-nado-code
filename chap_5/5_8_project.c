#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int num1, int num2, int level);
void success();
void fail();

int main(void){
    srand(time(NULL)); //난수 초기화
    int count = 0; //맞힌 문제 수
    for(int i = 1; i <=5 ;i++){
        int num1 = getRandomNumber(i); //난수 생성 함수
        int num2 = getRandomNumber(i);
        showQuestion(num1, num2, i); //문제 생성 함수
        int answer = -1; //입력 초기화, -1 입력시 강제 종료
        scanf("%d", &answer);
        if (answer == -1){
            printf("프로그램을 종료합니다.\n");
            exit(0); //0이면 정상종료, 1넣을 시 오류발생으로 인한 종료
        } else if (answer == num1 * num2){
            success(); //성공시 작동하는 함수
            count++; //성공시 맞힌 문제 수 +1
        } else if (answer != num1 * num2){
            fail(); //실패시 작동하는 함수
        }
    };
    printf("\n\n 비밀번호 %d개를 맞혔습니다. \n", count);
    return 0;
}

int getRandomNumber(int level){
    return rand() % (level * 9) + 1; //레벨 증가에 따른 난이도 증가
}
void showQuestion(int num1, int num2, int level){
    printf("\n\n### %d 번째 비밀번호 ######\n\n", level);
    printf("%d x %d ? \n\n", num1, num2);
    printf("#########################\n\n");
    printf("비밀번호를 입력하세요.(종료를 원하면 -1 입력)\n");

}
void success(){
    printf(">> 정답입니다!");
}
void fail(){
    printf(">> 오답입니다!");
}