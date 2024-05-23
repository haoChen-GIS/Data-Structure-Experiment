#pragma once
#include <malloc.h>
#include<stdio.h>
#include<stdlib.h>

/*该头文件包含数据结构预定义的常量以及类型*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //不可行
#define OVERFLOW -2   //溢出

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;

/*定义元素类型为整数类型*/
typedef int SElemType;

//栈是指仅在表尾进行插入和删除操作的线性表
//栈是先进后出的线性表，类似于铁路



// 链栈节点结构体
typedef struct StackNode {
    SElemType data;                   // 数据域
    struct StackNode* next;    // 指针域，指向下一个节点
} StackNode;

// 链栈结构体
typedef struct {
    StackNode* top;     // 指向栈顶节点的指针
    int count;          // 栈的元素个数
} LinkStack;

// 初始化链栈
void InitStack(LinkStack* S) 
{
    S->top = NULL;
    S->count = 0;
}

// 链栈置空
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

// 入栈
void Push(LinkStack* S, SElemType e) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
}

// 出栈
int Pop(LinkStack* S) {
    if (S->top == NULL) {
        printf("栈为空!\n");
        return -1;
    }
    StackNode* p = S->top;
    int x = p->data;
    S->top = p->next;
    S->count--;
    free(p);
    return x;
}

// 取栈顶元素
int GetTop(LinkStack* S) {
    if (S->top == NULL) {
        printf("栈为空！\n");
        return -1;
    }
    return S->top->data;
}

// 遍历链栈
void Out_Stack(LinkStack* S) {
    if (S->top == NULL) {
        printf("栈为空!\n");
        return;
    }
    StackNode* p = S->top;
    printf("当前栈内元素为: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


