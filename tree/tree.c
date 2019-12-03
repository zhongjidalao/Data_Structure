//树的双亲表示法结点结构定义
#define MAX_TREE_SIZE 100

//树结点的数据类型，暂定为整型
typedef int TElemType;

//结点结构
typedef struct PTNode{
    //结点数据
    TElemType data;
    int parent;
}PTNode;

//孩子结点
typedef struct CTNode{
    int chile;
    struct CTNode *next;
} *ChildPtr;

//表头结构
typedef struct{
    TElemType data;
    ChildPtr firstchild;
}CTBox;

//树结构
typedef struct{
    //结点数组
    CTBox nodes[MAX_TREE_SIZE];
    //根的位置和结点数
    int r,n;
}CTree;

//树的孩子兄弟表示法结构定义
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstchild,*rightsib;
}CSNode,*CSTree;