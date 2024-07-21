//
// Created by zyr on 2023/10/9.
//
#include <stdio.h>
#include <math.h>
int main(void){
    double x;
    int n;
    int i;
    double sum=0.0;
    double a=0;
    double output;

    scanf("%lf%d",&x,&n);

    for (i = 0; i < n+1; i++) {
        a=((pow(-1,i)* pow(x,2*i+1))/(2*i+1)*1.0);
        sum+=a;
    }
    output=4*sum;
    printf("%.10lf\n",output);


    return 0;
}
