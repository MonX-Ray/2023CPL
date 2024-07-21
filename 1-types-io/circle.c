//
// Created by zyr on 2023/9/23.
//

#include<stdio.h>
int main(void){
    const double PI=3.14159;
    int radius=10;


    double circumference=2*PI*radius;
    double area=PI*radius*radius;

    printf("radius=%d\n circumference=%.2f\n area=%.2f\n",
           radius,circumference,area);
    return 0;
}