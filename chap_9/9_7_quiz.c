#include <stdio.h>

//도서 관리 프로그램
struct book { // 도서 정보가 담긴 구조체
    int id; // 번호 (ID)
    char * title; // 제목
    int available; // 0 : 대출중, 1: 대출가능
};

// struct book shelves[4];
struct book shelves[4] = {{ 1, "C 입문편", 1 }, { 2, "Python 입문편", 1 },  { 3, "JS 입문편", 1 }, { 4, "C++ 입문편", 1 }} ;

// void initBooks();
void printBooks();
void scanfBooks();

int main(void){
    // initBooks();
    printBooks();
    scanfBooks()
    return 0;
}

// void initBooks(){ //도서 목록 저장 함수
//     shelves[0].id = 1;
//     shelves[0].title = "C 입문편";
//     shelves[0].available = 1;

//     shelves[1].id = 2;
//     shelves[1].title = "파이썬 기본편";
//     shelves[1].available = 1;

//     shelves[2].id = 3;
//     shelves[2].title = "자바 기본편";
//     shelves[2].available = 1;

//     shelves[3].id = 4;
//     shelves[3].title = "파이썬 중급편";
//     shelves[3].available = 1;
// }

void printBooks(){ //전체 도서 출력 함수
    printf("\n\n==전체 도서 정보==\n\n");
    for (int i = 0; i < 4; i++){
    printf("책 ID : %d\n", shelves[i].id);
    printf("책 이름 : %s\n", shelves[i].title);
    printf("대출 가능 여부 : %d\n", shelves[i].available);
    printf("\n");
    }
}

void scanfBooks() //빌리거나 반납할 책 입력하는 함수
{
    while(1)
    {
    int scanId;
    printf("빌리고자 하는 도서 번호를 입력하세요.(1~4) (종료는 -1 입력)");
    scanf("%d", &scanId);
    if (scanId == -1) //종료 조건
    {
        break;
    } else if (scanId > 0 && scanId < 5) 
    {
        if(shelves[scanId].available == 0) // 이미 빌린 상태면
        {
            shelves[scanId].available = 1; // 반납 상태로
            printf("반납했습니다."); 
        } else // 안 빌린 상태면
        {
            shelves[scanId].available = 0; // 대출불가 상태로
            printf("대출했습니다.");
        }
    } else //1~4 값이 아닐경우
    {
        printf("유효한 책 번호를 입력해주세요.\n");
        continue;
    }
    }
}