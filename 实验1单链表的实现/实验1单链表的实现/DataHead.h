#pragma once
#include<stdio.h>

///*该头文件包含数据结构预定义的常量以及类型*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //不可行
#define OVERFLOW -2   //溢出

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;

/*定义线性表内的元素类型为整数类型*/
typedef int ElemType;

typedef struct LNode {

    ElemType	data;		//数据域
    struct LNode* next;	   //指针域    存放下一结点的首地址
}LNode, * LinkList; //LNode型数据元素 ，指针类型 LinkList


/*函数声明*/
Status GetElem_L(LinkList L, int i, ElemType* e);       //算法2.8 链表元素的查找
Status ListInsert_L(LinkList* L, int i, ElemType e);		 //算法2.9  链表元素的插入
Status ListDelete_L(LinkList* L, int i, ElemType* e);  //算法2.10 链表元素的删除
void    CreateList_L(LinkList* L, int n);						//算法2.11  链表的创建
void    PrintList(LinkList L);						       //输出链表

Status GetElem_L(LinkList L, int i, ElemType* e)       /*  算法2.8元素的查找 */
{    

      /*  L为带头结点的单链表的头指针。 */
      /*  当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR */
    LinkList p;
    int j;
    p = L->next;
    j = 1;           /*  初始化，p指向第一个结点，j为计数器 */
    while (p && j < i) 
    {   
        /*顺指针向后查找，直到p指向第i个元素或p为空*/
        p = p->next; 
        ++j;
    }
    if (!p || j > i) return ERROR;  /*  第i个元素不存在 */
    *e = p->data;                       /*  取第i个元素 */
    return OK;
} /*  GetElem_L */


Status ListInsert_L(LinkList* L, int i, ElemType e) 
{
    //在带头节点指针的L的链表的第i个位置之前插入元素e
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)          //寻找第i-1个结点的位置
    {
        p = p->next;        //当j==i-2的时候，p->next指向第i-1个元素的首地址
        ++j;
    }
    if (!p || j > i - 1)return ERROR;     // i小于1或者大于表长+1（因为i<1时或者大于表长+1，p的指向就无法预测）                  
    LinkList s = (LinkList)malloc(sizeof(LNode));      //生成新的结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}//ListInsert_L

Status ListDelete_L(LinkList* L, int i, ElemType* e)
{
    //在带头节点的单链线性表L中，删除第i个元素，并由e返回其值
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1) {    //寻找第i个元素，并让p指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)return ERROR;        //删除的位置不合理
    LinkList q = p->next;   p->next = q->next;      //删除并释放结点
    e = q->data;
    free(q);
    return OK;
}//ListDelete_L

//（* LinkList 类型变量）==LNode , LinkList类型变量 == &LNode类型变量
//(* LinkList * 类型变量) == LinkList , LinkList*类型变量 == &LinkList类型变量

void CreateList_L(LinkList* L, int n)
{
    //逆位序输入n个元素的值，建立带有头节点的单链线性表
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = n; i > 0; --i) {
        LinkList p = (LinkList)malloc(sizeof(LNode)); //生成新的结点
        scanf_s("%d", &(p->data), sizeof(p->data));        //输入元素值
        p->next = (*L)->next;   //插入到表头         p->next为NULL
        (*L)->next = p;
    }
}	//CreateList_L



/*单链表的打印：*/
void PrintList(LinkList head)
{
    LinkList p;
    p = head->next;      /*回避头结点的数据域*/
    printf("链表元素是:\t");
    while (p) {
        printf("%d\t ", p->data);
        p = p->next;
    }
    printf("\n");
}


