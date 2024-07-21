//
// Created by zyr on 2023/9/30.
//
#include<stdio.h>
#include <math.h>
int main(void){
    double G=6.674e-11;
    double M=77.15;
    double m;
    double R;
    double f;

    scanf("%lf %lf",&m,&R);

    f=G*M*m/ pow(R,2);

    printf("%.3e",f);

    return 0;
}