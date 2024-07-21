//
// Created by zyr on 2023/11/30.
//
#include <stdio.h>
#include <stdlib.h>
#define N 100005
int main(void){
    char *S=(char*)malloc(N* sizeof(char));
    char *T=(char*)malloc(N* sizeof(char));
    scanf("%s%s",S,T);
    int i=0;
    while (*(S+i)!=0){
        int flag=0;
        if(*(S+i)==*T){
            for (int j = 1; *(T+j)!=0; ++j) {
                if(*(S+i+j)!=*(T+j)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("%d ",i);
            }
        }
        i++;
    }
    free(S);
    free(T);
    return 0;
}