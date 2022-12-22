#define _CRT_SECURE_NO_WARNINGS //보안 경고 무시
#include <stdio.h>

int main(void){
    FILE * file = fopen("//Users//유저이름//파일경로//test2.txt", "wb");
    // 파일에서 데이터 읽고 쓸 때에는 먼저 파일을 열어서 파일 포인터를 얻어야 한다.
    // 파일 포인터는 fopen() 함수를 통해 무슨 파일 열었는지, 어디까지 읽었는지, 파일 끝에 도달했는지 등의 정보를 담는다. (북마크 기능)
    // wb : 바이너리 데이터 쓰는 목적으로 새 파일 생성하겠다.
    if (file == NULL){
        // 파일 포인터로 파일에 텍스트를 쓰기 전에 파일 포인터 값이 NULL인지 확인해야 함. NULL일 경우 파일 생성 못했다는 뜻.
        printf("파일 열기 실패\n");
        return 1;
    }
    fputs("fputs() 함수로 글을 써 볼 게요.\n", file);
    //문자열 단위로 파일에 데이터를 쓸 때 사용
    fputs("잘 써지는지 확인해 주세요\n", file);
    fclose(file);
    return 0;

}