#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    FILE * file = fopen("//Users//유저이름//파일경로//test2.txt", "wb");
    //바이너리 데이터를 쓰는 목적으로 열기
    if (file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }
    fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호 ", 1,2,3,4,5,6);
    fprintf(file, "%s %d\n", "보너스번호  ", 7);
    fclose(file);
    return 0;
}