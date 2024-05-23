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

#define MAXSIZE 100 // 定义队列最大容量为100

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;

/*定义元素类型为整数类型*/
typedef int QElemType;

typedef struct {
    int data[MAXSIZE]; // 队列中的元素
    int front; // 队头下标
    int rear; // 队尾下标
} SqQueue;

// 初始化队列
void InitQueue(SqQueue* Q) {
    Q->front = Q->rear = 0;
}

// 判断队列是否为空
Status QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
    {
        return FALSE;
    }
}

// 判断队列是否已满
Status QueueFull(SqQueue Q) {
    if ((Q.rear + 1)  == Q.front)
        return   TRUE;
    else return FALSE;
}

// 入队
void EnQueue(SqQueue* Q, QElemType e) {
    if (QueueFull(*Q)) {
        printf("队列已满，无法入队\n");
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) ;
}

// 出队
int DeQueue(SqQueue* Q,QElemType *e) {
    if (QueueEmpty(*Q)) {
        printf("队列为空，无法出队\n");
        return -1;
    }
    int x = Q->data[Q->front];
    Q->front = (Q->front + 1) ;
    return x;
}

// 取队列头元素
int GetHead(SqQueue Q) {
    if (QueueEmpty(Q)) {
        printf("队列为空，无法取队头元素\n");
        return -1;
    }
    return Q.data[Q.front];
}

// 遍历队列
void TraverseQueue(SqQueue Q) {
    if (QueueEmpty(Q)) {
        printf("队列为空，无法遍历\n");
        return;
    }
    printf("队列元素为：");
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.data[i]);
        i = i + 1;
    }
    printf("\n");
}