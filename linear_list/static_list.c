#include <stdio.h>
#include <stdlib.h>

/**
 * 静态链表
*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType data;
	//游标（Cursor）,为0时表示无指向
	int cur;
}Component,StaticLinkList[MAXSIZE];

//返回L中数据元素个数
int ListLengh(StaticLinkList L){
	int j = 0;
	int i = L[MAXSIZE-1].cur;
	while(i){
		i = L[i].cur;
		j++;
	}
	return j;
}

//space[0].cur为头指针，"0"表示空指针
Status InitList(StaticLinkList space){
	int i;
	for(i=0; i<MAXSIZE-1; i++){
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;

	return OK;
}

//静态链表的插入操作

//若备用空间链表非空，则返回的分配的结点下标，否则返回0
//取待插入的新结点
int Maloc_SLL(StaticLinkList space){
	//当前数组第一个元素的cur存的值，为第一个备用空闲的下标
	int i = space[0].cur;
	//由于要拿出一个分量来使用，所以我们就得把它下一个分量拿来做备用
	if(space[0].cur){
		space[0].cur = space[i].cur;
	}
	return i;
}

//在L中第i个元素之前插入新的元素e
Status ListInsert(StaticLinkList L, int i, ElemType e){
	int j, k, l;
	//k首先是最后一个元素的下标
	k = MAXSIZE - 1;
	if(1<1 || i>ListLengh(L)+1)
		return ERROR;
	//获得空闲分量的下标 
	j = Maloc_SLL(L);
	if(j){
		//将数据赋值给此分量的data
		L[j].data = e;
		//找到第i个元素之前的位置
		for(l=1; l<=i-1; i++)
			k = L[k].cur;
		//把第i个元素之前的cur赋值给新元素的cur
		L[j].cur = L[k].cur;
		//把新元素的下标赋值给第i个元素之前元素的cur
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

//奖下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space, int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//删除操作,删除在L中的第i个元素e
Status ListDelete(StaticLinkList L, int i){
	int j, k;
	if(i<1 || i>ListLengh(L))
		return ERROR;
	k = MAXSIZE - 1;
	for(j=1; j<=i-1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}

Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
            visit(L[i].data);
            i=L[i].cur;
            j++;
    }
    return j;
    printf("\n");
    return OK;
}

void displsy(StaticLinkList L){
	int i = L[0].cur;
	for(int j=0; j<=i; j++){
		printf("%d \n", visit(L[j].data));
	}
}

int main(){
	StaticLinkList L;
	Status i;
	i = InitList(L);
	printf("%d\n", ListLengh(L));

	ListInsert(L,1,'F');
	ListInsert(L,1,'F');
	ListInsert(L,1,'F');
	ListInsert(L,1,'F');

	displsy(L);
}