//
// Created by zyr on 2023/9/30.
//
#include <stdio.h>
#include <math.h>
int main (void){
    int year,month,day;
    scanf("%d %d %d",&year,&month,&day);

    int a=(14-month)/12;
    int y=year+4800-a;
    int m=month+12*a-3;
    int JDN;
    JDN = day +(153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;



    printf("%d %d %d %d",JDN,a,y,m);
    return 0;
}
