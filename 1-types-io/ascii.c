//
// Created by zyr on 2023/9/29.
//
#include <stdio.h>
int main(void){
    const int ASCII=32;
    int number;

    scanf("%d",&number);

    printf("%d\t%pascal\n"
           "%d\t%pascal\n",
           number,number,
           number+32,number+32);//tolower or toupper in <ctype.h>表示小写和大写
    return 0;
}

