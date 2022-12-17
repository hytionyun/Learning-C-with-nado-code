#include <stdio.h>

int main(void){
    printf("\n");
    int arr[3] = {5, 10, 15};
    for (int i = 0; i < 3; i++){
        printf("\n");
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
        printf("배열 arr[%d]의 값 : %d\n", i, *(arr+i));
        /* arr은 배열의 첫 번째 요소의 주소를 가지고 있어서( arr==&arr[0]; ) arr[i]는 i 번째에 해당하는 요소의 값을 가져오게 됨. */
        /* 따라서 두 문장은 완전히 같은 문장임( *(arr+1) == arr[i]; ) */
    }
    printf("\n");
    int * ptr = arr;
    for (int i = 0; i < 3; i++){
        printf("포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
        printf("포인터 변수 ptr[%d]의 값 : %d\n", i, *(ptr+i));
        /* ptr에 arr을 바로 넣어준 것임 */
    }
    printf("\n");
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    for (int i = 0; i < 3; i++){
        printf("포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
        /* 포인터 변수에서 값을 바꾸면 포인터 변수의 값과 가리키는 배열의 값도 바뀌게 됨 */
    }
    printf("\n");
    printf("arr 자체의 값(주소) : %p\n", arr);
    printf("arr 의 실제 값 : %d\n", *arr);
    printf("arr[0]의 주소 : %p\n", &arr[0]);
    printf("arr[0]의 실제 값 : %d\n", *&arr[0]);
    /* arr[0] == arr + 0 == arr == *&[arr] */
    /* * : 주소의 값, & : 주소 ... 따라서 둘이 상쇄됨. */
    return 0;
}