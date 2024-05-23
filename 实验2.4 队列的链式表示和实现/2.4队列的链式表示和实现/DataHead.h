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

/*����Ԫ������Ϊ��������*/
typedef int QElemType;

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;

typedef struct QNode      //�����������
{
	QElemType        data;     //������Ϊ����Ԫ��
	struct QNode* next;		 
} QNode, * QueuePtr;

typedef struct 
{
	QueuePtr    front;			   //����ָ��
	QueuePtr    rear;			  //��βָ��
}LinkQueue;


/*����˵��*/

Status InitQueue(LinkQueue *Q); //����һ���ն���
Status DestroyQueue(LinkQueue* Q);   //���ٶ���	Q,  Q���ٴ���
Status ClearQueue(LinkQueue* Q);  //��Q��Ϊ�ն���
Status QueueEmpty(LinkQueue Q);//��Ϊ�շ���TRUE������FALSE
Status QueueLength (LinkQueue Q);//���ض��еĳ���
Status GetHead(LinkQueue Q,QElemType *e);//�����в��գ���e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status EnQueue(LinkQueue *Q, QElemType e);//����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue(LinkQueue* Q, QElemType* e);//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ�����e����ֵ��������OK������ERROR
Status TraverseQueue(LinkQueue Q);


// ��ʼ��������
Status InitQueue(LinkQueue* Q) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->next = NULL;
    Q->front = Q->rear = p;
}

// �ж��������Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q) 
{
    if (Q.front == Q.rear)
        return OK;
    else
        return FALSE;
}

// ��Ӳ���
Status EnQueue(LinkQueue* Q, QElemType e) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // �½ڵ���뵽��β
    Q->rear = p; // �޸Ķ�βָ��
}

// ���Ӳ���
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

// ����������
Status TraverseQueue(LinkQueue Q) 
{
    QNode* p = Q.front->next; // �Ӷ�ͷ�ڵ㿪ʼ����
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