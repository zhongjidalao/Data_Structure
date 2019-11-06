#include <stdio.h>
#include <stdlib.h>

#define Size 5

typedef struct Table{
    //声明了一个动态数组
    int *head;
    //记录数据的长度
    int length;
    //记录表的长度
    int size;
}table;

table initTable(){
    table t;
    t.head = (int*)malloc(Size*sizeof(int));
    if(!t.head){
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}

//elem为插入元素，add为插入位置
table addTable(table t, int elem, int add){
    if(add>t.length+1 || add<1){
        printf("插入位置有问题");
        return t;
    }

    if(t.length >= t.size){
        t.head = (int*)realloc(t.head, (t.size+1)*sizeof(int));
        if(!t.head){
            printf("存储分配失败");
        }
        t.size += 1;
    }

    for(int i=t.length-1; i>=add-1; i--){
        t.head[i+1] = t.head[i];
    }

    t.head[add-1] = elem;
    t.length++;
    return t;
}

//删除操作
table delTable(table t, int add){
    if(add>t.length || add<1){
        printf("被删除的位置有误");
        exit(0);
    }

    for(int i=add; i<t.length; i++){
        t.head[i-1] = t.head[i];
    }

    t.length--;
    return t;
}

//查找操作
int selectTable(table t, int elem){
    for(int i=0; i<t.length; i++){
        if(t.head[i] == elem){
            return i+1;
        }
    }
    return -1;
}

//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table amendTable(table t, int elem, int newElem){
    int add = selectTable(t, elem);
    t.head[add-1] = newElem;
    return t;
}

//遍历顺序表元素
void displayTable(table t){
    for(int i=0; i<t.length; i++){
        printf("%d", t.head[i]);
    }
    printf("\n");
}

int main(){
    table t1 = initTable();
    // t1.head[0] = 1;
    // t1.head[1] = 2;
    // t1.head[2] = 3;
    // t1.head[3] = 4;
    // t1.head[4] = 5;

    // t1.length = 5;

    // displayTable(t1);

    for (int i=1; i<=Size; i++) {
        t1.head[i-1]=i;
        t1.length++;
    }
    printf("原顺序表：\n");
    displayTable(t1);

    printf("删除元素1：\n");
    t1 = delTable(t1, 1);
    displayTable(t1);

    printf("在第二的位置插入元素5：\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);

    printf("查找元素3的位置:\n");
    int add=selectTable(t1, 3);
    printf("%d\n",add);

    printf("将元素3改为6:\n");
    t1=amendTable(t1, 3, 6);
    displayTable(t1);
    return 0;
}