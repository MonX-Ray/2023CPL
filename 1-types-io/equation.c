//
// Created by zyr on 2023/9/30.
//
#include <stdio.h>
#include <math.h>

int main(void){
    int p,q;
    double x;

    scanf("%d %d",&p,&q);

    double m= cbrt(-q/2.0+ sqrt(pow(q/2.0,2)+ pow(p/3.0,3)));
    double n= cbrt(-q/2.0-sqrt(pow(q/2.0,2)+ pow(p/3.0,3)));//合起来写就不对了

    x=m+n;

    printf("%.3lf",x);
    return 0;
}