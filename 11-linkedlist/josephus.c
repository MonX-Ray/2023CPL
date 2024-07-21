//
// Created by zyr on 2023/12/30.
//
#include <stdio.h>
#include "linked.h"
#include <assert.h>

void SitAroundCircle(LinkedList *list, int num);

void KillUntilOne(LinkedList *list,int p);

int GetVal(const LinkedList *list);

int main(void) {
    int num = 0;
    int step = 0;
    int key=0;
    scanf("%d%d%d", &num, &step,&key);
    LinkedList list;
    Init(&list);
    SitAroundCircle(&list, num);

    int anss= (Search(&list,key))->index;
    KillUntilOne(&list,step);
    int ans = GetVal(&list);
    printf("%d\n%d", ans,anss);
    return 0;
}

void SitAroundCircle(LinkedList *list, int num) {
    for (int i = 1; i < num + 1; ++i) {
        Append(list, i);
    }
}

void KillUntilOne(LinkedList *list,int p) {
    int k=1;
    Node *node = list->head;
    while (!IsSingleton(list)){
        if(k==p-1){
            Delete(list,node);
            k=1;
        }else{
            k+=1;
        }
        node=node->next;
    }
}

int GetVal(const LinkedList *list){
    return list->head->index;
}