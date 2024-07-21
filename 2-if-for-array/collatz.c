//
// Created by zyr on 2023/10/9.
//
#include <stdio.h>
#include <math.h>

int main(){
    int number=0;
    int step=0;
    int max;
    scanf("%d",&number);
    int item[100000]={number};


    for (int i = 0; number!=1; i++) {
        if(number%2==0){
            number /=2;
        }else{
            number=3*number+1;
        }
        item[i+1]=number;
        step++;
    }

    max=item[0];

    for (int i = 0; item[i]!=1; ++i) {
        if(max < item[i]){
            max=item[i];
        }
    }
    printf("%d %d",step,max);

    return 0;
}