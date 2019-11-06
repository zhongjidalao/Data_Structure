#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

//类型根据实际情况而定，这里假设为int
typedef int SElemType;
typedef int Status;

typedef struct{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

//进栈push操作
Status Push(SqStack *S, SElemType e){
    if(S->top == MAXSIZE - 1){
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

//出栈pop操作
Status Pop(SqStack *S, SElemType *e){
    if(S->top == -1){
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
