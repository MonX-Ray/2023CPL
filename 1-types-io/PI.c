//
// Created by zyr on 2023/9/29.
//
#include<stdio.h>
#include<math.h>
int main(void){
    double PI=log(pow(640320,3)+744)/sqrt(163);
    double PII=4*(4*atan(1.0/5)-atan(1.0/239));

    printf("%.15lf\n%.15lf\n",
           PI,PII);


    return 0;
}