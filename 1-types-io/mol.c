//
// Created by zyr on 2023/9/23.
//

#include <stdio.h>
int main(void){
    const double MOL=6.02E23;
    const double GRAM_PER_MOL=32;

    int mass=6;
    double quantity=mass*1.0/GRAM_PER_MOL*MOL;

    printf("quantity=%.3e\nquantity=%.5g\n",
           quantity,quantity);




    return 0;
}