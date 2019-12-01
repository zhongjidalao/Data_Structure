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

//树结构
typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;
}PTree;