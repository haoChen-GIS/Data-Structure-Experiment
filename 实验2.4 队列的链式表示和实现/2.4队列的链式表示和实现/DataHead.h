#pragma once
#include <stdio.h>
#include <stdlib.h>
/*该头文件包含数据结构预定义的常量以及类型*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //不可行
#define OVERFLOW -2   //溢出

/*定义元素类型为整数类型*/
typedef int QElemType;

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;

typedef struct QNode      //结点数据类型
{
	QElemType        data;     //数据域为整形元素
	struct QNode* next;		 
} QNode, * QueuePtr;

typedef struct 
{
	QueuePtr    front;			   //队首指针
	QueuePtr    rear;			  //队尾指针
}LinkQueue;


/*函数说明*/

Status InitQueue(LinkQueue *Q); //构建一个空队列
Status DestroyQueue(LinkQueue* Q);   //销毁队列	Q,  Q不再存在
Status ClearQueue(LinkQueue* Q);  //将Q清为空队列
Status QueueEmpty(LinkQueue Q);//若为空返回TRUE，否则FALSE
Status QueueLength (LinkQueue Q);//返回队列的长度
Status GetHead(LinkQueue Q,QElemType *e);//若队列不空，用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue(LinkQueue *Q, QElemType e);//插入元素e为Q的新的队尾元素
Status DeQueue(LinkQueue* Q, QElemType* e);//若队列不空，则删除Q的队头元素，并用e返回值，并返回OK，否则ERROR
Status TraverseQueue(LinkQueue Q);


// 初始化链队列
Status InitQueue(LinkQueue* Q) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->next = NULL;
    Q->front = Q->rear = p;
}

// 判断链队列是否为空
Status QueueEmpty(LinkQueue Q) 
{
    if (Q.front == Q.rear)
        return OK;
    else
        return FALSE;
}

// 入队操作
Status EnQueue(LinkQueue* Q, QElemType e) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // 新节点插入到队尾
    Q->rear = p; // 修改队尾指针
}

// 出队操作
Status DeQueue(LinkQueue* Q, QElemType* e)
{
    if (Q->front == Q->rear)return ERROR;
    QNode* p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)Q->rear = Q->front;
    free(p);
    return OK;
}

// 遍历链队列
Status TraverseQueue(LinkQueue Q) 
{
    QNode* p = Q.front->next; // 从队头节点开始遍历
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status DestroyQueue(LinkQueue* Q)
{
    while (Q->front)
    {
        Q->rear = Q->rear->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}