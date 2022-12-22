#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int main(void){
    char str1[MAX]; //추첨번호 문자열 저장할 공간
    char str2[MAX]; //보너스번호 문자열 저장할 공간
    int num[6] = {0, 0, 0, 0, 0, 0}; //읽어온 추첨번호 저장할 정수형 배열
    int bonus = 0;//읽어온 보너스번호 저장할 정수형 배열

    FILE * file = fopen("//Users//유저이름//파일경로//test2.txt", "rb");
    //바이너리 데이터를 읽는 목적으로 열기
    if (file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]); //test2.txt파일의 내용 읽어오고 이를 저장할 주소 적기 (이때 배열명 자체가 배열의 시작 주소임 그래서 str1으로 적으면 됨)
    printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
    fscanf(file, "%s %d", str2, &bonus); //'보너스번호' 문자열은 str2에 저장하고 보너스 번호인 7인 bonus 변수에 저장
    printf("%s %d\n", str2, bonus);
    fclose(file);

    return 0;
}