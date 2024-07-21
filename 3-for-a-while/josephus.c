//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void){
    int n=0;
    int k=0;
    int jo[10005]={0};
    int step=0;
    scanf("%d%d",&n,&k);
    int alive=n;

    while(alive>1) {
        for (int i = 1; i < n + 1; ++i) {
            if (jo[i] == 0) {
                step++;
                if (step == k) {
                    jo[i] = 1;
                    alive = alive - 1;
                    step = 0;
                }
            }
        }
    }

    for (int i = 1; i < n+1; ++i) {
        if(jo[i]==0){
            printf("%d",i);
        }
    }
    return 0;
}