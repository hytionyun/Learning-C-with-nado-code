#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000 //코드 내 MAX라는 값이 사용되면 10000으로 치환하겠다

int main(void){
    char line[MAX]; //fgets 함수로 파일에서 값을 읽어와 출력하기 위해선 보관장소 필요
    //파일 모드를 rb로 설정 (데이터 읽기 전용)
    FILE * file = fopen("//Users//유저이름//파일경로//test2.txt", "rb");
    if (file == NULL){
        printf("파일 열기 실패.\n");
        return 1;
    }
    while (fgets(line, MAX, file) != NULL){ //fgets(변수명(저장소), 문자열 최대 크기, 파일 포인터(북마크))
        //fgets는 한 번 읽을 때 한번에 읽을 수 있는 문자열의 길이만큼 읽음 (문자열의 최대 크기)
        //fgets : 문자열 단위로 파일에 데이터를 읽을 때 사용
        //줄바꿈 문자 읽으면 읽기를 중단하고(문자열의 끝은 널문자이므로) MAX-1까지의 문자열만 입력받고 마지막에 널 문자 추가 후 다음 반복 실행
        //세 번째 반복 시 읽을 문자열 없고 널 문자만 추가되므로 반복 종료
        printf("%s", line); //line에 저장된 값 출력
    } 
    fclose(file);
    return 0;
}

