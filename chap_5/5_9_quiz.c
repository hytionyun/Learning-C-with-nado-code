#include <stdio.h>

void convert_time(int minute);

int main(void){
    int minute;
    printf("분 -> 시간 + 분 변환기, 변환할 분이 몇 분인지 입력해주세요. \n");
    scanf("%d", &minute);
    convert_time(minute);
    return 0;
}

void convert_time(int minute){
    int hour;
    
    hour = minute / 60;
    minute = minute % 60;
    if (hour > 0){
        printf("%d시간 %d분\n", hour, minute);
    } else {
        printf("%d분\n", minute);
    }
}