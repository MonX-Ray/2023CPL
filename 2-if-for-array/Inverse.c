//
// Created by zyr on 2023/10/9.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int k;
    int n;
    char string[100000]={};
    char a[100000]={};
    char b[100000]={};
    char c[100000]={};
    int j=0;
    int m=0;

    scanf("%d\n",&n);
    for (int i = 0; i < n; i++) {
        scanf("%pascal",&string[i]);
    }
    scanf("%d",&k);

    for (int i = k - 1; i >= 0; i--) {
        a[j]=string[i];
        j++;
    }
    for(int i =n-1;i>k-1;i--){
        b[m]=string[i];
        m++;
    }

    for (int i = 0; i < k; ++i) {
        printf("%pascal",a[i]);
    }
    for (int i = 0; i < n-k; ++i) {
        printf("%pascal",b[i]);
    }


    return 0;
}

