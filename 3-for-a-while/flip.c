//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(void){
    int num[2000]={0};
    int n;
    int m;

    scanf("%d",&n);
    for (int i = 1; i < n+1; ++i) {
        for (int k = 1; i*k<n+1; ++k) {
            m=i*k;
            if(num[m]==1){
                num[m]=0;
            }else{
                num[m]=1;
            }
        }
    }
    for (int i = 1; i < n+1; ++i) {
        if(num[i]==1){
            printf("%d ",i);
        }
    }
    return 0;
}