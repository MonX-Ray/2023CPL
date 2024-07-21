//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>
int sum(int n);
int main(void){
    int n=0;
    scanf("%d",&n);
    printf("%d", sum(n));
    return 0;
}
int sum(int n){
    if(n==2){
        return 2;
    }else if(n==1){
        return 1;
    }else{
        return sum(n-1)+sum(n-2);
    }
}