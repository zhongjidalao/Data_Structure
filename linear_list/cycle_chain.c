#include <stdio.h>

//定义链表结构
typedef struct CLinkList{
    int data;
    struct CLinnkList *next;
}node;

//初始化循环链表
void ds_init(node **pNode){
    int item;
    node *temp;
    node *target;

    printf("输入结点的值，输入0完成初始化\n");

    while(1){
        scanf("%d", &item);
        fflush(stdin);

        if(item == 0)
            return;
        
        if((*pNode) == NULL){
            *pNode = (node*)malloc(sizeof(struct CLinkList));
            if(!(*pNode))
                exit(0);
            (*pNode)->data = item;
            (*pNode)->next = *pNode;
        }else{
            //找到next指向第一个结点的结点
            for(target = (*pNode); target->next != (*pNode); target = target->next){

            }

            temp = (node *)malloc(sizeof(struct CLinkList));

            if(!temp)
                exit(0);
            temp->data = item;
            temp->next = *pNode;
            target->next = temp;
        }
    }

}

//插入结点
void ds_insert(node **pNode, int i){
    node *temp;
    node *target;
    node *p;
    int item;
    int j = 1;

    printf("输入要插入结点的值：");
    scanf("%d", &item);

    if(i == 1){
        //新插入的结点作为第一个结点
        temp = (node *)malloc(sizeof(struct CLinkList));

        if(!temp){
            exit(0);
        }
        temp->data = item;

        for(target = (*pNode); target->next != (*pNode); target = target->next)
            ;
        temp->next = (*pNode);
        target->next = temp;
        *pNode = temp;
    }else{
        target = *pNode;

        for( ; j< (i-1); ++j){
            target = target->next;
        }

        temp = (node *)malloc(sizeof(struct CLinkList));

        if(!temp){
            exit(0);
        }
        temp->data = item;
        p = target->next;
        target->next = temp;
        temp->next = p;
    }
}