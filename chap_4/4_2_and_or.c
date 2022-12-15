#include <stdio.h>

int main(void){
    int a, b, c, d;
    printf("a를 입력해주세요 : ");
    scanf("%d", &a);
    printf("b를 입력해주세요 : ");
    scanf("%d", &b);
    printf("c를 입력해주세요 : ");
    scanf("%d", &c);
    printf("d를 입력해주세요 : ");
    scanf("%d", &d);
    if (a==b && c==d){ //AND 연산자는 &&, OR 연산자는 ||
        printf("a, b가 같고 c, d가 같다.\n");
    } else if (a==b && c!=d){
        printf("a, b가 같고 c, d가 다르다.\n");
    } else if (a!=b && c==d){
        printf("a, b가 다르고 c, d가 같다.\n");
    } else if (a!=b && c!=d){
        printf("a, b가 다르고 c, d가 다르다.\n");
    }
    return 0;
}