#pragma once
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>

/*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //������
#define OVERFLOW -2   //���

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;

/*����Ԫ������Ϊ��������*/
typedef int SElemType;

//ջ��ָ���ڱ�β���в����ɾ�����������Ա�
//ջ���Ƚ���������Ա���������·



// ��ջ�ڵ�ṹ��
typedef struct StackNode {
    SElemType data;                   // ������
    struct StackNode* next;    // ָ����ָ����һ���ڵ�
} StackNode;

// ��ջ�ṹ��
typedef struct {
    StackNode* top;     // ָ��ջ���ڵ��ָ��
    int count;          // ջ��Ԫ�ظ���
} LinkStack;

// ��ʼ����ջ
void InitStack(LinkStack* S) 
{
    S->top = NULL;
    S->count = 0;
}

// ��ջ�ÿ�
void ClearStack(LinkStack* S) {
    StackNode* p, * q;
    p = S->top;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    S->top = NULL;
    S->count = 0;
}

// ��ջ
void Push(LinkStack* S, SElemType e) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
}

// ��ջ
int Pop(LinkStack* S) {
    if (S->top == NULL) {
        printf("ջΪ��!\n");
        return -1;
    }
    StackNode* p = S->top;
    int x = p->data;
    S->top = p->next;
    S->count--;
    free(p);
    return x;
}

// ȡջ��Ԫ��
int GetTop(LinkStack* S) {
    if (S->top == NULL) {
        printf("ջΪ�գ�\n");
        return -1;
    }
    return S->top->data;
}

// ������ջ
void Out_Stack(LinkStack* S) {
    if (S->top == NULL) {
        printf("ջΪ��!\n");
        return;
    }
    StackNode* p = S->top;
    printf("��ǰջ��Ԫ��Ϊ: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


