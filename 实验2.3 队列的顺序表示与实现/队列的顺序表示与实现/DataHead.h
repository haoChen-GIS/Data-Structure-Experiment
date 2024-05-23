#pragma once
#include <stdio.h>
#include <stdlib.h>
/*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //������
#define OVERFLOW -2   //���

#define MAXSIZE 100 // ��������������Ϊ100

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;

/*����Ԫ������Ϊ��������*/
typedef int QElemType;

typedef struct {
    int data[MAXSIZE]; // �����е�Ԫ��
    int front; // ��ͷ�±�
    int rear; // ��β�±�
} SqQueue;

// ��ʼ������
void InitQueue(SqQueue* Q) {
    Q->front = Q->rear = 0;
}

// �ж϶����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
    {
        return FALSE;
    }
}

// �ж϶����Ƿ�����
Status QueueFull(SqQueue Q) {
    if ((Q.rear + 1)  == Q.front)
        return   TRUE;
    else return FALSE;
}

// ���
void EnQueue(SqQueue* Q, QElemType e) {
    if (QueueFull(*Q)) {
        printf("�����������޷����\n");
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) ;
}

// ����
int DeQueue(SqQueue* Q,QElemType *e) {
    if (QueueEmpty(*Q)) {
        printf("����Ϊ�գ��޷�����\n");
        return -1;
    }
    int x = Q->data[Q->front];
    Q->front = (Q->front + 1) ;
    return x;
}

// ȡ����ͷԪ��
int GetHead(SqQueue Q) {
    if (QueueEmpty(Q)) {
        printf("����Ϊ�գ��޷�ȡ��ͷԪ��\n");
        return -1;
    }
    return Q.data[Q.front];
}

// ��������
void TraverseQueue(SqQueue Q) {
    if (QueueEmpty(Q)) {
        printf("����Ϊ�գ��޷�����\n");
        return;
    }
    printf("����Ԫ��Ϊ��");
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.data[i]);
        i = i + 1;
    }
    printf("\n");
}