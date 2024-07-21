//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>
#include <string.h>
#define N 1005
int main(void){
    int a=0;
    int b=0;
    int c=0;
    scanf("%d%d%d",&a,&b,&c);
    int x=0;
    int xx=a;
    int y=0;
    int yy=b;
    char order[N]={0};
    scanf("%s",order);
    int len=(int)strlen(order);
    for (int i = 0; i < len; ++i) {
        int temp=0;
        if(order[i]=='W'){
            xx=x;
            x-=c;
            temp=a;
            a=c;
            c=temp;
        }else if(order[i]=='S'){
            x=xx;
            xx+=c;
            temp=a;
            a=c;
            c=temp;
        }else if(order[i]=='A'){
            yy=y;
            y-=c;
            temp=b;
            b=c;
            c=temp;
        }else if(order[i]=='D'){
            y=yy;
            yy+=c;
            temp=b;
            b=c;
            c=temp;
        }
    }
    printf("%d %d %d %d",x,xx,y,yy);
    return 0;
}