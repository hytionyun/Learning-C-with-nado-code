#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10000

int main(void){
    char password[20]; //비번 저장용
    char line[MAX]; //읽어온 내용 저장용, 줄별로 최대 10000글자씩 읽어오도록 선언
    char contents[MAX] = ""; //일기장에 입력한 내용 저장할 변수

    printf("비밀일기에 오신걸 환영합니다\n");
    printf("비밀번호 입력\n");
    scanf("%s", password);

    if (strcmp(password, "hytion") == 0){ //비밀번호 맞을 경우
        //두 문자열 비교(string.h 헤더파일 필요), 같으면 0, 1이크면 1, 2가 크면 -1 반환
        printf("비밀번호 확인 완료\n");

        char *fileName = "/Users/사용자 이름/경로/secretDiary.txt";
        FILE *file = fopen(fileName, "a+b"); //a모드 : 파일 없으면 생성, 있으면 뒤부터 읽고쓰기 가능+바이너리모드
        if (file == NULL){
            printf("파일이 없어서 열 수 없습니다.\n");
            return 1; //종료
        }

        fseek(file, 0, SEEK_SET); // 파일 위치 지시자를 파일의 맨 앞으로 이동

        while (fgets(line, MAX, file) != NULL){ //\0나올때까지 파일 출력
            printf("%s", line);
        }

        printf("\n\n내용을 계속작성하세요\n\n");
        while(1){
            scanf("%[^\n]", contents); //줄바꿈 문자 전까지 읽어옴
            getchar(); // Enter(\n) 입력 시 플러시 처리
            if (strcmp(contents, "EXIT") == 0){
                printf("비밀 일기 입력 종료\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);// Enter를 위에서 무시하도록 처리했으므로 임의로 추가
        }
        fclose(file);
    } else {
        printf("비밀번호 오류\n");
    }

    return 0;
}


