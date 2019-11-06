#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link{
    int elem;
    struct Link *next;
}link;

//创建链表的函数
link *initLink(){
	//创建一个头节点
	link *p = (link*)malloc(sizeof(link));
	//声明一个指针指向头节点，用于遍历链表
	link *temp = p;

	//生成链表
	for(int i=1; i<5; i++){
		//创建节点并初始化
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		//建立新节点与直接前驱节点的逻辑关系
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link *insertElem(link *p, int elem, int add){
	link *temp = p;

	//找到要插入位置的上一个结点
	for(int i=1; i<add; i++){
		temp = temp->next;
		if(temp == NULL){
			printf("插入位置无效\n");
			return p;
		}
	}
	//创建插入结点
	link *c = (link*)malloc(sizeof(link));
	c->elem = elem;
	//向链表插入结点
	c->next = temp->next;
	temp->next = c;
	return p;
}

//p为原链表，add为要删除元素的位置
link *delElem(link *p, int add){
	link *temp = p;
	//遍历到被删除结点的上一个结点
	for(int i=1; i<add; i++){
		temp = temp->next;
		if(temp->next == NULL){
			printf("没有该结点\n");
			return p;
		}
	}
	link *del = temp->next;
	temp->next = temp->next->next;
	free(del);
	return p;
}

//p为原链表，elem表示被查找元素
int selectElem(link *p, int elem){
	//新建一个指针t，初始化为头指针p
	link *t = p;
	int i = 1;

	//由于头节点的存在，因此while重的判断为t->next
	while(t->next){
		t = t->next;
		if(t->elem == elem){
			return i;
		}
		i++;
	}
	return -1;
}

//更新函数，其中add表示更改结点在链表重的位置，newElem为新的数据域的值
link *amendElem(link *p, int add, int newElem){
	link *temp = p;
	//在遍历之前，temp指向首元结点
	temp = temp->next;
	//遍历到待更新结点
	for(int i=1; i<add; i++){
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}

void display(link *p){
	link *temp = p;
	while(temp->next){
		temp = temp->next;
		printf("%d ", temp->elem);
	}
	printf("\n");
}

int main(){
	printf("初始化链表为：\n");
	link *p = initLink();
	display(p);

	printf("在第四的位置插入元素5\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("删除第五个元素5\n");
	p = delElem(p, 5);
	display(p);
}