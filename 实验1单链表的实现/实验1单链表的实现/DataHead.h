#pragma once
#include<stdio.h>

///*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //������
#define OVERFLOW -2   //���

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;

/*�������Ա��ڵ�Ԫ������Ϊ��������*/
typedef int ElemType;

typedef struct LNode {

    ElemType	data;		//������
    struct LNode* next;	   //ָ����    �����һ�����׵�ַ
}LNode, * LinkList; //LNode������Ԫ�� ��ָ������ LinkList


/*��������*/
Status GetElem_L(LinkList L, int i, ElemType* e);       //�㷨2.8 ����Ԫ�صĲ���
Status ListInsert_L(LinkList* L, int i, ElemType e);		 //�㷨2.9  ����Ԫ�صĲ���
Status ListDelete_L(LinkList* L, int i, ElemType* e);  //�㷨2.10 ����Ԫ�ص�ɾ��
void    CreateList_L(LinkList* L, int n);						//�㷨2.11  ����Ĵ���
void    PrintList(LinkList L);						       //�������

Status GetElem_L(LinkList L, int i, ElemType* e)       /*  �㷨2.8Ԫ�صĲ��� */
{    

      /*  LΪ��ͷ���ĵ������ͷָ�롣 */
      /*  ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR */
    LinkList p;
    int j;
    p = L->next;
    j = 1;           /*  ��ʼ����pָ���һ����㣬jΪ������ */
    while (p && j < i) 
    {   
        /*˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��*/
        p = p->next; 
        ++j;
    }
    if (!p || j > i) return ERROR;  /*  ��i��Ԫ�ز����� */
    *e = p->data;                       /*  ȡ��i��Ԫ�� */
    return OK;
} /*  GetElem_L */


Status ListInsert_L(LinkList* L, int i, ElemType e) 
{
    //�ڴ�ͷ�ڵ�ָ���L������ĵ�i��λ��֮ǰ����Ԫ��e
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)          //Ѱ�ҵ�i-1������λ��
    {
        p = p->next;        //��j==i-2��ʱ��p->nextָ���i-1��Ԫ�ص��׵�ַ
        ++j;
    }
    if (!p || j > i - 1)return ERROR;     // iС��1���ߴ��ڱ�+1����Ϊi<1ʱ���ߴ��ڱ�+1��p��ָ����޷�Ԥ�⣩                  
    LinkList s = (LinkList)malloc(sizeof(LNode));      //�����µĽ��
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}//ListInsert_L

Status ListDelete_L(LinkList* L, int i, ElemType* e)
{
    //�ڴ�ͷ�ڵ�ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1) {    //Ѱ�ҵ�i��Ԫ�أ�����pָ����ǰ��
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)return ERROR;        //ɾ����λ�ò�����
    LinkList q = p->next;   p->next = q->next;      //ɾ�����ͷŽ��
    e = q->data;
    free(q);
    return OK;
}//ListDelete_L

//��* LinkList ���ͱ�����==LNode , LinkList���ͱ��� == &LNode���ͱ���
//(* LinkList * ���ͱ���) == LinkList , LinkList*���ͱ��� == &LinkList���ͱ���

void CreateList_L(LinkList* L, int n)
{
    //��λ������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = n; i > 0; --i) {
        LinkList p = (LinkList)malloc(sizeof(LNode)); //�����µĽ��
        scanf_s("%d", &(p->data), sizeof(p->data));        //����Ԫ��ֵ
        p->next = (*L)->next;   //���뵽��ͷ         p->nextΪNULL
        (*L)->next = p;
    }
}	//CreateList_L



/*������Ĵ�ӡ��*/
void PrintList(LinkList head)
{
    LinkList p;
    p = head->next;      /*�ر�ͷ����������*/
    printf("����Ԫ����:\t");
    while (p) {
        printf("%d\t ", p->data);
        p = p->next;
    }
    printf("\n");
}


