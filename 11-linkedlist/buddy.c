//
// Created by zyr on 2023/12/31.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int size;
    bool used;
    int id;
    struct node *next;
} Node;

typedef struct ll {
    Node *head;
} LinkedList;

Node *Search(LinkedList *ll, int k,const int name);

void Split(LinkedList *ll, int k);

void Print(LinkedList *ll);

int Count(LinkedList *ll);


int main(void) {
    int n = 0;
    int q = 0;
    int nums[]={1,2,3,4};
    scanf("%d%d", &n, &q);
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->head= malloc(sizeof(Node));
    ll->head->size = n;
    ll->head->next = NULL;
    ll->head->used=false;
    for (int i = 0; i < q; ++i) {
        getchar();
        char key;
        scanf("%c", &key);
        if (key == 'Q') {
            printf("%d\n", Count(ll));
            Print(ll);
        }
        if (key == 'A') {
            int name=0;
            scanf("%d",&name);
            int ko = 0;
            scanf("%d", &ko);
            int k=0;
            for (int j = 0; ; ++j) {
                if(pow(2,j)>=ko){
                    k=j;
                    break;
                }
            }
            Search(ll, k, name);
        }
    }
    free(ll);
    return 0;
}

Node *Search(LinkedList *ll, int k, const int name) {
    Node *new = ll->head;
    while (new != NULL) {
        if (new->size == k && new->used == false) {
            new->id=name;
            new->used = true;
            return new;
        }
        new = new->next;
    }
    if (new == NULL) {
        Split(ll, k);
        Search(ll,k,name);
    }
}

void Split(LinkedList *ll, int k) {
    Node *p = ll->head;
    while (p != NULL) {
        if (p->size > k && p->used == false) {
            Node *new = malloc(sizeof(Node));
            new->used=false;
            new->size=p->size-1;
            p->size=p->size-1;
            Node *temp=p->next;
            p->next=new;
            new->next=temp;
            return;
        }
        p=p->next;
    }
}

int Count(LinkedList *ll) {
    Node *a = ll->head;
    int ans = 0;
    while (a != NULL) {
        ans++;
        a = a->next;
    }
    return ans;
}

void Print(LinkedList *ll){
    Node *a=ll->head;
    while (a!=NULL){
        if(a->used==true){
            printf("%d ",a->id);
        }else{
            printf("0 ");
        }
        a=a->next;
    }
    printf("\n");
}