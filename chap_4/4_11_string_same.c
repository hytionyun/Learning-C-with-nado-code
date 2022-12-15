#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr1[10];
    char arr2[10];

    printf("2 개의 문자열 : ");
    scanf("%s %s", arr1, arr2);

    int res = strcmp(arr1, arr2);

    if (res == 0){
        printf("2개 문자열이 같음 \n");
    } else if (res > 0){
        printf("1번 문자열이 큼 \n");
    } else {
        printf("2번 문자열이 큼 \n");
    }
    return 0;
}