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


/*栈的顺序存储表示*/  /*  p46 */
#define STACK_INIT_SIZE 4         //存储空间初始分配量    
#define STACKINCREMENT 1        //存储空间分配增量

typedef struct
{
	SElemType* base;    //在栈构造之前和销毁之后，base的值为NULL
	SElemType* top;		//栈顶指针
	int stacksize;			//当前已分配的存储空间，以元素为单位
}SqStack;


typedef int SElemType;    //定义元素类型为整形
/*函数申明*/
Status InitStack(SqStack* L);   /*  p47 */
Status GetTop(SqStack S, SElemType* e);
Status Push(SqStack* L, SElemType e);   /* 进栈，插入 */
Status Pop(SqStack* L, SElemType* e);   /*  出栈，删除*/
void Out_Stack(SqStack L);    /*补充，输出打印栈*/

//算法2.3
Status InitStack(SqStack* S)       //构建栈
{  /*  p47 */
  /*  构造一个空栈 */
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);        /*  存储分配失败 */
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;   /*  初始存储容量 */
    return OK;
} /*  InitStack */


Status GetTop(SqStack S, SElemType* e)  //返回栈顶元素
{ 
    /*  p47 */
/* 此处要求自己参考课本补充代码……*/
    if (S.top = S.base)return ERROR;
    e = S.top - 1;
    return OK;
} /*  GetTop */


Status Push(SqStack* S, SElemType e) //入栈算法
{  /*  P47 */

    if (S->top - S->base >= S->stacksize) {   /*  当前存储空间已满，增加容量 */
        S->base = (SElemType*)realloc(S->base,
            (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) exit(OVERFLOW);   /*  存储分配失败 */
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;  /*  增加存储容量 */
    }
    *S->top++ = e;       /* 请同学注释此句，或分拆*/
    return OK;
} /*  Push */

Status Pop(SqStack* S, SElemType* e)         //出栈算法
{  /*  p47 */

/* 此处要求自己参考课本补充代码……*/
    if (S->top == S->base)return  ERROR;
    e = --S->top;
    return OK;
} /*  Pop */


void Out_Stack(SqStack L)               //从栈底到栈顶输出栈内元素
{
    int* i;
    printf("\n当前栈内元素从栈底到栈顶为：");
    for (i = L.base; i < L.top; i++) printf("%10d", *i);
}
