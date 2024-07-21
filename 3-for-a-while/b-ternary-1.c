//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(void){
    int n;
    int m = 0;
    int len;
    char s[100];
    int a = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        m=0;
        getchar();
        scanf("%s", s);
        len = strlen(s);
        for (int j = 0; j < len; ++j) {
            if (s[j] == 'Z' || s[j] == '0' || s[j] == '1') {
                a = 0;
            } else {
                a = 1;
                break;
            }
        }
        if(a==1){
            printf("Radix Error\n");
        }else{
            for (int j = len-1,temp=1; j >=0 ; --j,temp*=3) {
                if(s[j]=='Z'){
                    m=m+(-1)*temp;
                }else if(s[j]=='0'){
                    m=m;
                }else {
                    m=m+temp;
                }
            }
            printf("%d\n",m);}
    }
    return 0;
}


