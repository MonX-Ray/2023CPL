//
// Created by zyr on 2023/9/29.
//
#include<stdio.h>
int main(void){

    char month[10];
    char weekday[10];
    int day,hour,minute,second,year;

    scanf("%s%d%d%s%d%d%d",&month,&day,&year,&weekday,&hour,&minute,&second);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",weekday,month,day,hour,minute,second,year);

    return 0;
}