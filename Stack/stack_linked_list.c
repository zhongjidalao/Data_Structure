#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;

//插入元素e为新的栈顶元素
Status Push(LinkStack *S, SElemType e){
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}


//斐波那契数列
// int main(){
// 	int i;
// 	int a[40];
// 	a[0] = 0;
// 	a[1] = 1;
// 	printf("%d\n", a[0]);
// 	printf("%d\n", a[1]);
// 	for(i = 2; i<40; i++){
// 		a[i] = a[i-1] + a[i-2];
// 		printf("%d\n", a[i]);
// 	}
// 	return 0;
// }

//斐波那契数列的递归函数
int Fbi(int i){
	if(i < 2){
		return i == 0 ? 0 : 1;
	}
	return Fbi(i-1) + Fbi(i-2);//这里Fbi就是函数自己，它在调用自己
}

int main(){
	int i;
	for(int i=0; i<40; i++){
		printf("%d\n", Fbi(i));
	}
	return 0;
}
