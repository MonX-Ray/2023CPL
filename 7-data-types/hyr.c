//
// Created by zyr on 2023/11/19.
//
#include <stdio.h>

int main(void) {
    int m = 0;
    int n = 0;
    int nums = 0;
    scanf("m=%d,n=%d", &m, &n);
    for (int i = 0; i < n - m + 1; ++i) {//遍历m到n判断题目
        int flag=0;//用于判断是否符合前两个条件
        nums = m + i;
        if (nums >= 100 && nums < 1000){//第一个条件
            for (int j = 2; j <nums ; ++j) {//15到19行用于判断是否是素数（常用代码段）
                if(nums%j==0){
                    flag=1;//如果飞啦给，则不符合第二个条件，不进行第20行以后的判断
                }
            }
            if(flag==0){
                int copy=nums;//copy用于计算个十百位数
                int a=copy%10;
                copy=copy/10;
                int b=copy%10;
                copy=copy/10;
                int c=copy%10;
                if((a+b)%10==c){//第三个条件
                    printf("%d %d %d %d\n",nums,a,b,c);
                }
            }
        }
    }
    return 0;
}