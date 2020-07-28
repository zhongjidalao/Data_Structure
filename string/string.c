#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define linkNum 3//全局设置链表中节点存储数据的个数

typedef struct Link {
    char a[linkNum]; //数据域可存放 linkNum 个数据
    struct Link * next; //代表指针域，指向直接后继元素
}link; // nk为节点名，每个节点都是一个 link 结构体
link * initLink(link * head, char * str);
void displayLink(link * head);
int main()
{
    link * head = NULL;
    head = initLink(head, "data.biancheng.net");
    displayLink(head);
    return 0;
}
//初始化链表，其中head为头指针，str为存储的字符串
link * initLink(link * head, char * str) {
    int length = strlen(str);
    //根据字符串的长度，计算出链表中使用节点的个数
    int num = length/linkNum;
    if (length%linkNum) {
        num++;
    }
    //创建并初始化首元节点
    head = (link*)malloc(sizeof(link));
    head->next = NULL;
    link *temp = head;
    //初始化链表
    for (int i = 0; i<num; i++)
    {
        int j = 0;
        for (; j<linkNum; j++)
        {
            if (i*linkNum + j < length) {
                temp->a[j] = str[i*linkNum + j];
            }          
            else
                temp->a[j] = '#';
        }
        if (i*linkNum + j < length)
        {
            link * newlink = (link*)malloc(sizeof(link));
            newlink->next = NULL;
            temp->next = newlink;
            temp = newlink;
        }
    }
    return head;
}
//输出链表
void displayLink(link * head) {
    link * temp = head;
    while (temp) {
        for (int i = 0; i < linkNum; i++) {
            printf("%c", temp->a[i]);
        }
        temp = temp->next;
    }
}

//朴素的匹配算法
int Index(String S, String T, int pos){
    int i = pos;
    int j = 1;

    while (i <= S[0] && j <= T[0]){
        if (S[i] == T[j]){
            ++i;
            ++j;
        }else{
            //如果匹配不到，就从S的第二个和T的第一个开始重新匹配
            i = i-j+2;
            j = 1;
        }
    }

    if (j > T[0]){
        return i-T[0];
    }else{
        return 0;
    }
    
}