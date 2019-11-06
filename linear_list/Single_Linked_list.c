#include <stdio.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

//单链表结构体
typedef struct  Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;

//查找元素
Status GetElem(LinkList L, int i, ElemType *e){
    int j;
    LinkList p;

    p = L->next;
    j = 1;

    while (p && j < i){
        p = p->next;
        ++j;
    }

    if(!p || j > i){
        return ERROR;
    }

    *e = p->data;

    return OK;
}

//插入操作
Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p = *L;
    j = 1;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof (Node));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除操作
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p->next && j < i){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->next;
    free(q);
    return OK;
}

//单链表的整表创建
//头插法
void CresteListHead(LinkList *L, int n){
    LinkList p;
    int i;
    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for(i=0; i<n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//尾插法
void CreateListTail(LinkList *L, int n){
    LinkList p, r;
    int i;

    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    
    r = *L;

    for(i=0; i<n; i++){
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

//单链表的整表删除
Status ClearList(LinkList *L){
    LinkList p, q;
    p = (*L)->next;

    while(p){
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return 0;
}

