//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    int k;
    char s[10000]={0};
    char a[10000]={0};
    char b[10000]={0};
    int i;
    int m=0;
    int j=0;

    scanf("%d\n",&n);
    scanf("%s",&s);
    scanf("%d",&k);

    for(i=k-1;i>=0;i--){
        a[m]=s[i];
        m++;
    }

    for(i=n-1;i>=k;i--){
        b[j]=s[i];
        j++;
    }

    printf("%d\n", n);
    printf("%s",a);
    printf("%s\n",b);
    printf("%d\n", k);
    return 0;
}

