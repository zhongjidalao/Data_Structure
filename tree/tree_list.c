#include <stdio.h>
#include <stdlib.h>

//树的双亲表示法结点结构定义
#define MAX_TREE_SIZE 100

//树结点的数据类型，暂定为整型
typedef int TElemType;

//二叉树的二叉链表结点结构定义
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉树的前序遍历递归算法
void PreOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}