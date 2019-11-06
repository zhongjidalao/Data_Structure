#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;

//顺序队列的顺序存储结构
typedef struct{
	QElemType data[MAXSIZE];
	//头指针
	int front;
	//尾指针
	int rear;
}SqQueue;

//初始化一个空队列Q
Status InitQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//返回Q的元素个数，也就是队列的当前长度
it QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//若队列未满，则插入元素e为Q新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e){
	if((Q->rear+1) %MAXSIZE == Q->front){
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;

	return OK;
}

//若队列不空，则删除Q中队头元素，用e返回其值
Status DeQueue(SqQueue *Q, QElemType *e){
	if(Q->front == Q->rear){
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;

	return OK;
}