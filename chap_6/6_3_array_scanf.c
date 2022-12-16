#include <stdio.h>

int main (void){
    char name[256];
    printf("이름이 뭔가요?");
    scanf("%s", name);
    //window 기준 : scanf_s("%s", name, sizeof(name));
    printf("%s\n\n", name);

    //ASCII코드 출력해보기
    printf("%c\n", 'a');
    printf("%d\n", 'a');

    printf("%c\n", '\0');
    printf("%d\n", '\0');
    return 0;
}
