//
// Created by zyr on 2023/11/30.
//
#include <stdio.h>
int main(void){
    int x=0;
    scanf("%x",&x);
    printf("%d\n",*(int*)&x);
    printf("%u\n",*(unsigned int*)&x);
    printf("%.6f\n",*(float*)&x);
    printf("%.3e\n",*(float*)&x);
    return 0;
}