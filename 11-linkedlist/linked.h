//
// Created by zyr on 2023/12/30.
//实现链表的基本操作

#ifndef INC_2023_LINKED_H
#define INC_2023_LINKED_H

#include <stdbool.h>

typedef int Item;

typedef struct node {
    Item index;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} LinkedList;

void Init(LinkedList *list);

void Free(LinkedList *list);

bool IsEmpty(const LinkedList *list);

bool IsSingleton(const LinkedList *list);

int GetHeadVal(const LinkedList *list);

void Print(const LinkedList *list);

void Append(LinkedList *list, Item index);

void Delete(LinkedList *list, Node *prev);

void Insert(LinkedList *list, Node *prev,Item index);

Node *Search(LinkedList *list, Item index);

#endif //INC_2023_LINKED_H
