//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STACK_SIZE 10000
char contents[STACK_SIZE];
int top=0;
void make_empty(void){
    top=0;
}
bool is_empty(void){
    return top==0;
}
bool is_full(void){
    return top==STACK_SIZE;
}
void push(char a){
    if(is_full()){
        ;
    }else{
        contents[top++]=a;
    }
}
char pop(void){
    if(is_empty()){
        ;
    }else{
        return contents[--top];
    }
}

int main(void){
    int T=0;
    char str[STACK_SIZE]={0};
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int flag=0;
        scanf("%s",str);
        int len= strlen(str);
        for (int j = 0; j < len; ++j) {
            if(str[j]=='('||str[j]=='['||str[j]=='{'){
                push(str[j]);
            }else if(str[j]==')'){
                if(contents[top-1]=='('){
                    pop();
                }else{
                    flag=1;
                    break;
                }
            }else if(str[j]==']'){
                if(contents[top-1]=='['){
                    pop();
                }else{
                    flag=1;
                    break;
                }
            }else if(str[j]=='}'){
                if(contents[top-1]=='{'){
                    pop();
                }else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            printf("False\n");
        }else if(is_empty()){
            printf("True\n");
        }
        make_empty();
    }
    return 0;
}
