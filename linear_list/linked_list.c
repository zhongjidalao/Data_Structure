#include <stdio.h>
#include <stdlib.h>

//单链表
typedef struct Link{
    //代表数据域
    char elem;
    //代表指针域，指向直接后继元素
    struct Link * next;
}link;

// 存储1，2，3，4且无头节点的链表
link * initLink(){
    //创建头指针
    link *p = NULL;
    //创建首元节点
    link *temp = (link*)malloc(sizeof(link));
    //首元节点初始化
    temp->elem = 1;
    temp->next = NULL;
    //头指针指向首元节点
    p = temp;

    //从第二个节点开始创建
    for(int i=2; i<5; i++){
        //创建一个新节点并初始化
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //将temp节点与新建立的节点a建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就说a节点，这里写temp=a也对
        temp = temp->next;
    }
    return p;
}

//创建一个储存1，2，3，4，且含头节点的链表
// link *initLink(){
//     link *p = (link*)malloc(sizeof(link));
//     link *temp = p;

//     //生成链表
//     for(int i=1; i<5; i++){
//         link *a = (link*)malloc(sizeof(link));
//         a->elem = i;
//         a->next = NULL;
//         temp->next = a;
//         temp = temp->next;
//     }
//     return p;
// }

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p = initLink();
    display(p);
    return 0;
}