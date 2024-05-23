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


/*ջ��˳��洢��ʾ*/  /*  p46 */
#define STACK_INIT_SIZE 4         //�洢�ռ��ʼ������    
#define STACKINCREMENT 1        //�洢�ռ��������

typedef struct
{
	SElemType* base;    //��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType* top;		//ջ��ָ��
	int stacksize;			//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;


typedef int SElemType;    //����Ԫ������Ϊ����
/*��������*/
Status InitStack(SqStack* L);   /*  p47 */
Status GetTop(SqStack S, SElemType* e);
Status Push(SqStack* L, SElemType e);   /* ��ջ������ */
Status Pop(SqStack* L, SElemType* e);   /*  ��ջ��ɾ��*/
void Out_Stack(SqStack L);    /*���䣬�����ӡջ*/

//�㷨2.3
Status InitStack(SqStack* S)       //����ջ
{  /*  p47 */
  /*  ����һ����ջ */
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);        /*  �洢����ʧ�� */
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;   /*  ��ʼ�洢���� */
    return OK;
} /*  InitStack */


Status GetTop(SqStack S, SElemType* e)  //����ջ��Ԫ��
{ 
    /*  p47 */
/* �˴�Ҫ���Լ��ο��α�������롭��*/
    if (S.top = S.base)return ERROR;
    e = S.top - 1;
    return OK;
} /*  GetTop */


Status Push(SqStack* S, SElemType e) //��ջ�㷨
{  /*  P47 */

    if (S->top - S->base >= S->stacksize) {   /*  ��ǰ�洢�ռ��������������� */
        S->base = (SElemType*)realloc(S->base,
            (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) exit(OVERFLOW);   /*  �洢����ʧ�� */
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;  /*  ���Ӵ洢���� */
    }
    *S->top++ = e;       /* ��ͬѧע�ʹ˾䣬��ֲ�*/
    return OK;
} /*  Push */

Status Pop(SqStack* S, SElemType* e)         //��ջ�㷨
{  /*  p47 */

/* �˴�Ҫ���Լ��ο��α�������롭��*/
    if (S->top == S->base)return  ERROR;
    e = --S->top;
    return OK;
} /*  Pop */


void Out_Stack(SqStack L)               //��ջ�׵�ջ�����ջ��Ԫ��
{
    int* i;
    printf("\n��ǰջ��Ԫ�ش�ջ�׵�ջ��Ϊ��");
    for (i = L.base; i < L.top; i++) printf("%10d", *i);
}
