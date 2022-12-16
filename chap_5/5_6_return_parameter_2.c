#include <stdio.h>

int apple(int total, int ate); 
void p(int num1, int num2, int num3);

int main(void){
    int ret, total_ret, ate_ret;
    printf("총 사과의 개수를 입력해 주세요 : ");
    scanf("%d", &total_ret);
    printf("먹은 사과의 개수를 입력해 주세요 : ");
    scanf("%d", &ate_ret);
    ret = apple(total_ret, ate_ret); 
    p(total_ret, ate_ret, ret);    
    return 0;
}

int apple(int total, int ate){
    printf("전달값과 반환값이 있는 함수입니다.\n");
    return total - ate;
}

void p(int num1, int num2, int num3){
    printf("사과 %d개 중에서 %d개를 먹으면 %d개가 남습니다.\n", num1, num2, num3);
}