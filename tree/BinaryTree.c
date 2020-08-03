#define OK 1

typedef enum {Link, Thread} PointerTag;

typedef int TElemType;
typedef int Status;

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTage;
    PointerTag RTage;
} BiThrNode, *BiThrTree;

//全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

//中序遍历进行中序线索化
void InThreading(BiThrTree p){
    if (p){
        InThreading(p->lchild);
        if(!p->lchild){
            p->LTage = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild){
            pre->RTage = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

Status InOrderTraverse_Thr(BiThrTree T){
    BiThrTree p;

    p = T->lchild;

    while(p != T){
        while (p->LTage == Link)
        {
            p = p->lchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}
