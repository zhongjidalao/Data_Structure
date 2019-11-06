#include <stdio.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct  Node
{
    ElemType data;
    struct Node *next; 
} Node;
typedef struct Node *LinkList;

Status GetMidNode(LinkList L, ElemType *e){
    LinkList search, mid;
    mid = search = L;

    while(search->next != NULL){
        if(search->next->next != NULL){
            search = search->next->next;
            mid = mid->next;
        }else{
            search = search->next;
        }
    }
    *e = mid->data;
    return OK;
}
