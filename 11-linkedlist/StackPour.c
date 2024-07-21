//
// Created by zyr on 2023/12/31.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10005
typedef struct node {
    int num;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Stack *a[N];

void Init(Stack *sta, int num);

void push(Stack *sta, int num);

int pop(Stack *sta);

void pour(int x, int y);

void Print(Stack *sta);

bool IsEmpty(const Stack *sta);

int main(void) {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n + 1; ++i) {
        a[i]= malloc(sizeof(Stack));
        Init(a[i], i);
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        pour(x, y);
    }
    for (int i = 1; i < n+1; ++i) {
        if (!IsEmpty(a[i])) {
            Print(a[i]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}

void Init(Stack *sta, int num) {
    Node *new_node = malloc(sizeof(Node));
    new_node->num = num;
    sta->top = new_node;
    new_node->next = NULL;
}

bool IsEmpty(const Stack *sta) {
    return sta->top == NULL;
}

int pop(Stack *sta) {
    Node *old = sta->top;
    int ans = sta->top->num;
    sta->top = sta->top->next;
    free(old);
    return ans;
}

void push(Stack *sta, int num) {
    Node *new = malloc(sizeof(Node));
    new->num = num;
    new->next=sta->top;
    sta->top=new;
}

void pour(int x, int y){
    if(IsEmpty(a[x])){
        return;
    }
    if(a[y]->top==NULL){
        a[y]= malloc(sizeof(Stack));
        a[y]->top=NULL;
    }
    while (a[x]->top!=NULL){
        int num= pop(a[x]);
        push(a[y],num);
    }
}

void Print(Stack *sta){
    int ans[N];
    int step=0;
    while (sta->top!=NULL){
        ans[step]= pop(sta);
        step++;
    }
    for (int i = step-1; i >-1; --i) {
        printf("%d ",ans[i]);
    }
    printf("\n");
}
