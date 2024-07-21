//
// Created by zyr on 2023/10/9.
//有没有更简单的做法
#include <stdio.h>

int main(void){
    int n;
    int i,b;
    int factorial=1;
    int numbers[25]={};
    int factor[25]={};
    int item[25]={};
    int a[25]={};//
    int sum=0;
    int output;

    scanf("%d",&n);


    if(n<=10){for (int i = 0; i < n; i++) {
        factorial*=(i+1);
        item[i]=factorial%10007;
    }}else{
        for (int i = 0; i < 10; i++) {
            factorial*=(i+1);
            item[i]=factorial%10007;
        }
        for (int i = 10; i < n; i++) {
            item[i]=item[i-1]*(i+1)%10007;
        }
    }


    for (int i = 0; i < n; i++) {
        sum +=item[i];

    }
    output=sum%10007;


    printf("%d\n", output);



    return 0;
    }
