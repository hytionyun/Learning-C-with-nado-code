#include <stdio.h>

struct book {
    int id;
    char *title;
    int available;
};

void print_books(struct book *books);

int main (void) {
    struct book books[4] = {
        { 1, "C 입문편", 1 }, { 2, "Python 입문편", 1 },  { 3, "JS 입문편", 1 }, { 4, "C++ 입문편", 1 }
    };
    int input;
    while(1){
        print_books(books);
        printf("대출/반납할 책 번호 입력 (종료:-1) : ");
        scanf("%d", &input);
        if (input == -1){
            printf("프로그램 종료\n");
            break;
        }
        if (input < 1 || input > 4){
            printf("잘못된 입력\n");
            continue;
        }
        input -= 1;
        if (books[input].available ==0){
            printf("'%s' 반납이 완료되었습니다.\n", books[input].title);
            books[input].available = 1;
        } else{
            printf("'%s' 대출이 완료되었습니다.\n", books[input].title);
            books[input].available = 0;
        }
    }
    return 0;
}

void print_books(struct book *books)
{
    char * available = "대출 가능";
    char * unavailable = "대출 불가능";
    printf("전체 도서 목록 \n");
    for (int i = 0; i< 4 ; i++){
        printf("%d. %-16s", books[i].id, books[i].title);
        if (books[i].available){
            printf("[%s]\n", available);
        } else {
            printf("[%s]\n", unavailable);
        }
    }
};
