#pragma once

/*该头文件包含数据结构预定义的常量以及类型*/
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


#define LIST_INIT_SIZE 100      //线性表初始大小
#define LISTINCREMENT 10    //内存增量

typedef struct 
{
	ElemType* elem;
	int      length;
	int      listsize;
}SqList;

/*函数申明*/
Status InitList_Sq(SqList* L);   /*  算法2.3 */
void Out_List(SqList L);    /*补充，输出打印线性表*/
Status ListInsert_Sq(SqList* pL, int i, ElemType e);   /*  算法2.4 */
Status ListDelete_Sq(SqList* L, int i, ElemType* e);   /*  算法2.5 */
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));   /*  算法2.6 */


Status InitList_Sq(SqList* L) {  /*  算法2.3 */
  /*  构造一个空的线性表L。 */
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);        /*  存储分配失败 */
    L->length = 0;                                   /*  空表长度为0 */
    L->listsize = LIST_INIT_SIZE;        /* 初始存储容量 */
    return OK;
} /*  InitList_Sq */

Status ListInsert_Sq(SqList* L, int i, ElemType e)
{ 
   /*  算法2.4 */
  /*  在顺序线性表L的第i个元素之前插入新的元素e， */
  /*  i的合法值为1≤i≤ListLength_Sq(L)+1 */
    ElemType* p, * q;
    if (i < 1 || i > L->length + 1) return ERROR;/*  插入位置 i 值不合法 */
    if (L->length >= L->listsize) 
    {   
        /* 当前存储空间已满，增加容量 */
        ElemType* newbase = (ElemType*)realloc(L->elem,
        (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);     /*  存储分配失败 */
        L->elem = newbase;                       /*  新基址 */
        L->listsize += LISTINCREMENT;  /*  增加存储容量 */
    }
    q = &(L->elem[i - 1]);                       /* 数组从0开始存储，q为插入位置 */
    for (p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p;    /*  插入位置及之后的元素右移 */
    *q = e;              /*  插入e */
    ++L->length;   /*  表长增1 */
    return OK;
} /*  ListInsert_Sq */



Status ListDelete_Sq(SqList* L, int i, ElemType* e) {  /*  算法2.5 */
  /*  在顺序线性表L中删除第i个元素，并用e返回其值。 */
  /*  i的合法值为1≤i≤ListLength_Sq(L)。 */
    ElemType* p, * q;
    if (i<1 || i>L->length) return ERROR;     /*  删除位置i值不合法 */
    p = &(L->elem[i - 1]);                            /*  p为被删除元素的位置 */
    *e = *p;                                                /*  被删除元素的值赋给e */
    q = L->elem + L->length - 1;              /*  表尾元素的位置 */
    for (++p; p <= q; ++p)
        *(p - 1) = *p;                                      /* 被删除元素之后的元素左移 */
    --L->length;                                      /*  表长减1 */
    return OK;
} /*  ListDelete_Sq */


void Out_List(SqList L) {
    int i;
    printf("\n当前线性表为：");
    for (i = 0; i < L.length; i++)
    printf("%10d", L.elem[i]);      /*输出线性表的元素*/
}



int LocateElem_Sq(SqList L, ElemType e,Status(*compare)(ElemType, ElemType)) 
{ 
    /*  算法2.6 */
    /*  在顺序线性表L中查找第1个值与e满足compare()的元素的位序。 */
    /*  若找到，则返回其在L中的位序，否则返回0。 */
    int i;
    ElemType* p;
    i = 1;        /*  i的初值为第1个元素的位序 */
    p = L.elem;   /*  p的初值为第1个元素的存储位置 */
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length) return i;
    else return 0;
} /*  LocateElem_Sq */

Status compare(ElemType e, ElemType e1)
{
        if (e == e1)return OK;    //如果两个元素值相等，返回OK
        else
        {
            return ERROR;
        }
}