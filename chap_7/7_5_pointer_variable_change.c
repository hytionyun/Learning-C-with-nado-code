#include <stdio.h>

void swap(int num1, int num);
void swap_addr(int *num1, int *num2);

int main(void){
    int num1 = 0;
    int num2 = 0;
    printf("\n");
    printf("두 변수 바꾸기\n");
    printf("\n");
    printf("첫 번째 변수를 입력해주세요. : ");
    scanf("%d", &num1);
    printf("두 번째 변수를 입력해주세요. : ");
    scanf("%d", &num2);
    printf("\n");
    printf("두 변수의 위치가 바뀌었습니다. \n");
    printf("\n");
    swap(num1, num2); // 값을 전달했을 때의 함수
    printf("swap ");
    printf("함수 밖에서의 첫 번째 변수는 .. %d, 두 번째 변수는 .. %d\n", num1, num2);
    printf("\n");
    printf("num1의 주소 : %p\n", &num1);
    printf("num2의 주소 : %p\n", &num2);
    printf("\n");
    swap_addr(&num1, &num2); //주소를 전달했을 때의 함수
    printf("swap_addr ");
    printf("함수 밖에서의 첫 번째 변수는 .. %d, 두 번째 변수는 .. %d\n", num1, num2);
    printf("\n");
    printf("num1의 주소 : %p\n", &num1);
    printf("num2의 주소 : %p\n", &num2);
    printf("\n");


    return 0;
}
void swap(int num1, int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("첫 번째 변수는 .. %d, 두 번째 변수는 .. %d\n", num1, num2);
    printf("\n");
    printf("함수 안에서 num1의 주소 : %p\n", &num1);
    printf("함수 안에서 num2의 주소 : %p\n", &num2);
    /* 함수 안에서 전달받은 변수는 그 자체가 아니라 값만 복사해서 사용한다. : 값에 의한 호출 (call by value) */   
}

void swap_addr(int *num1, int *num2){
    int temp;
    temp = *num1; //실제 값 교환
    *num1 = *num2;
    *num2 = temp;
    printf("첫 번째 변수는 .. %d, 두 번째 변수는 .. %d\n", *num1, *num2);
    printf("\n");
    printf("함수 안에서 num1의 주소 : %p\n", num1);
    printf("함수 안에서 num2의 주소 : %p\n", num2);
    /* 값이 아닌 주소를 전달했을 때 주소에 저장된 값을 바꾸어 줌 : 참조에 의한 호출 (call by reference) */
}

/* C언어에서는 값에 의한 호출 개념만 있다. 참조에 의한 호출은 없으며 포인터를 이용해 (함수 안에서 주소값을 참조해 값을 변경하여) 이를 흉내낸 것이다.  */