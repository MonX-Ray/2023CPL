//
// Created by zyr on 2023/9/29.
//不能用abcde！
#include<stdio.h>
#include<math.h>
int main(void){
    int money;
    int fifty,twenty,ten,five,one;

    scanf("%d",&money);

    fifty=money/50;
    twenty=(money-fifty*50)/20;
    ten=(money-fifty*50-twenty*20)/10;
    five=(money-fifty*50-twenty*20-ten*10)/5;
    one=(money-fifty*50-twenty*20-ten*10-five*5)/1;

    printf("%d\n%d\n%d\n%d\n%d\n",
           fifty,twenty,ten,five,one);

    return 0;
}