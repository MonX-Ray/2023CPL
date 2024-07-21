//
// Created by zyr on 2023/9/23.
//
#include <stdio.h>
int main(void){
    int radius=100;
    const double PI=3.14159;

    double surface_area=4*PI*radius*radius;
    double volume=4.0/3*PI*radius*radius*radius;

    printf("%-15.4f:surface_area\n%-15.4f:volume\n",
       surface_area,volume);



    return 0;
}
