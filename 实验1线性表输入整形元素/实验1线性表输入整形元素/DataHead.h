#pragma once

/*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
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


#define LIST_INIT_SIZE 100      //���Ա��ʼ��С
#define LISTINCREMENT 10    //�ڴ�����

typedef struct 
{
	ElemType* elem;
	int      length;
	int      listsize;
}SqList;

/*��������*/
Status InitList_Sq(SqList* L);   /*  �㷨2.3 */
void Out_List(SqList L);    /*���䣬�����ӡ���Ա�*/
Status ListInsert_Sq(SqList* pL, int i, ElemType e);   /*  �㷨2.4 */
Status ListDelete_Sq(SqList* L, int i, ElemType* e);   /*  �㷨2.5 */
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));   /*  �㷨2.6 */


Status InitList_Sq(SqList* L) {  /*  �㷨2.3 */
  /*  ����һ���յ����Ա�L�� */
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);        /*  �洢����ʧ�� */
    L->length = 0;                                   /*  �ձ���Ϊ0 */
    L->listsize = LIST_INIT_SIZE;        /* ��ʼ�洢���� */
    return OK;
} /*  InitList_Sq */

Status ListInsert_Sq(SqList* L, int i, ElemType e)
{ 
   /*  �㷨2.4 */
  /*  ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e�� */
  /*  i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1 */
    ElemType* p, * q;
    if (i < 1 || i > L->length + 1) return ERROR;/*  ����λ�� i ֵ���Ϸ� */
    if (L->length >= L->listsize) 
    {   
        /* ��ǰ�洢�ռ��������������� */
        ElemType* newbase = (ElemType*)realloc(L->elem,
        (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);     /*  �洢����ʧ�� */
        L->elem = newbase;                       /*  �»�ַ */
        L->listsize += LISTINCREMENT;  /*  ���Ӵ洢���� */
    }
    q = &(L->elem[i - 1]);                       /* �����0��ʼ�洢��qΪ����λ�� */
    for (p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p;    /*  ����λ�ü�֮���Ԫ������ */
    *q = e;              /*  ����e */
    ++L->length;   /*  ����1 */
    return OK;
} /*  ListInsert_Sq */



Status ListDelete_Sq(SqList* L, int i, ElemType* e) {  /*  �㷨2.5 */
  /*  ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ�� */
  /*  i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)�� */
    ElemType* p, * q;
    if (i<1 || i>L->length) return ERROR;     /*  ɾ��λ��iֵ���Ϸ� */
    p = &(L->elem[i - 1]);                            /*  pΪ��ɾ��Ԫ�ص�λ�� */
    *e = *p;                                                /*  ��ɾ��Ԫ�ص�ֵ����e */
    q = L->elem + L->length - 1;              /*  ��βԪ�ص�λ�� */
    for (++p; p <= q; ++p)
        *(p - 1) = *p;                                      /* ��ɾ��Ԫ��֮���Ԫ������ */
    --L->length;                                      /*  ����1 */
    return OK;
} /*  ListDelete_Sq */


void Out_List(SqList L) {
    int i;
    printf("\n��ǰ���Ա�Ϊ��");
    for (i = 0; i < L.length; i++)
    printf("%10d", L.elem[i]);      /*������Ա��Ԫ��*/
}



int LocateElem_Sq(SqList L, ElemType e,Status(*compare)(ElemType, ElemType)) 
{ 
    /*  �㷨2.6 */
    /*  ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ�� */
    /*  ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0�� */
    int i;
    ElemType* p;
    i = 1;        /*  i�ĳ�ֵΪ��1��Ԫ�ص�λ�� */
    p = L.elem;   /*  p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ�� */
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length) return i;
    else return 0;
} /*  LocateElem_Sq */

Status compare(ElemType e, ElemType e1)
{
        if (e == e1)return OK;    //�������Ԫ��ֵ��ȣ�����OK
        else
        {
            return ERROR;
        }
}