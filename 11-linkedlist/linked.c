//
// Created by zyr on 2023/12/30.
//
#include "linked.h"
#include <stdlib.h>
#include <stdio.h>

void Init(LinkedList *list) {
    list->tail = NULL;
    list->head = NULL;
}

void Free(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

bool IsEmpty(const LinkedList *list) {
    return list->head == NULL;
}

bool IsSingleton(const LinkedList *list) {
    return !IsEmpty(list) && list->head == list->tail;
}

int GetHeadVal(const LinkedList *list) {
    if (IsEmpty(list)) {
        return -1;
    }
    return list->head->index;
}

void Print(const LinkedList *list) {
    if (IsEmpty(list)) {
        return;
    }
    Node *node = list->head;
    do {
        printf("%d", node->index);
        node = node->next;
    } while (node != list->head);
}

void Append(LinkedList *list, Item index) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->index = index;
    if (IsEmpty(list)) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->tail->next = list->head;
}

void Delete(LinkedList *list, Node *prev) {
    if (IsEmpty(list)) {
        return;
    }
    if (IsSingleton(list)) {
        Init(list);
        free(list->head);
        return;
    }
    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next = next;
    if (cur == list->head) {
        list->head = next;
    }
    if (cur == list->tail) {
        list->tail = prev;
    }
    free(cur);
}

void Insert(LinkedList *list, Node *prev, Item index) {

    Node *new_node = malloc(sizeof(Node));
    new_node->index = index;

    if (IsEmpty(list)) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = new_node;
        return;
    }

    Node *cur=prev->next;
    prev->next=new_node;
    new_node->next=cur;
    if(prev==list->tail){
        list->tail=new_node;
    }
}

Node *Search(LinkedList *list, Item index){
    Node *p=list->head;
    do{
        if(p->index==index){
            return p;
        }else{
            p=p->next;
        }
    }while(p!=list->head);
    return NULL;
}


