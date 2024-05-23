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
typedef struct //ѧ������������
{
    char Name[20];    
    char StuNum[20];
    int Score;
}ElemType ;

/*���Ա�Ķ�̬����˳��洢�ṹ*/
#define LIST_INIT_SIZE 100        //���Ա�ĳ�ʼ�ռ�Ϊ100
#define LISTINCREMENT 10          //���Ա������Ϊ10

typedef struct {      //����SqlList���͵Ľṹ��
    ElemType* elem;
    int      length;
    int      listsize;
}SqList;


/*��������*/
Status InitList_Sq(SqList* L);   /* ��ʼ�����Ա� �㷨2.3 */    
void Out_List(SqList L);    /*������Ա�*/
Status ListInsert_Sq(SqList* pL, int i, ElemType e);   /* ���Ա�Ĳ���  �㷨2.4 */
Status ListDelete_Sq(SqList* L, int i, ElemType* e);   /*  ���Ա��ɾ�� �㷨2.5 */
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));/*  �㷨2.6 */


Status InitList_Sq(SqList* L) {  /*  �㷨2.3 */
  /*  ����һ���յ����Ա�L�� */
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) exit(OVERFLOW);        /*  �洢����ʧ�� */
    L->length = 0;                  /*  �ձ���Ϊ0 */
    L->listsize = LIST_INIT_SIZE;   /*  ��ʼ�洢���� */
    return OK;
} /*  InitList_Sq */

Status ListInsert_Sq(SqList* L, int i, ElemType e)
{  /*  �㷨2.4 */
  /*  ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e�� */
  /*  i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1 */
    ElemType* p, * q;
    if (i < 1 || i > L->length + 1) return ERROR;  /*  iֵ���Ϸ� */
    if (L->length >= L->listsize) 
    {   /*  ��ǰ�洢�ռ��������������� */
        ElemType* newbase = (ElemType*)realloc(L->elem,
            (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) return ERROR;   /*  �洢����ʧ�� */
        L->elem = newbase;             /*  �»�ַ */
        L->listsize += LISTINCREMENT;  /*  ���Ӵ洢���� */
    }
    q = &(L->elem[i - 1]);   /*  qΪ����λ�� */
    for (p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p;
    /*  ����λ�ü�֮���Ԫ������ */
    *q = e;       /*  ����e */
    ++L->length;   /*  ����1 */
    return OK;
} /*  ListInsert_Sq */

void Out_List(SqList L) {
    int i;
    printf("\n��ǰ���Ա�Ϊ��\n");
    for (i = 0; i < L.length; i++)
    {
        printf("%s\t%s\t%d\t", L.elem[i].Name,L.elem[i].StuNum , L.elem[i].Score);
    }
}

Status ListDelete_Sq(SqList* L, int i, ElemType* e) {  /*  �㷨2.5 */
  /*  ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ�� */
  /*  i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)�� */
    ElemType* p, * q;
    if (i<1 || i>L->length) return ERROR;  /*  iֵ���Ϸ� */
    p = &(L->elem[i - 1]);                   /*  pΪ��ɾ��Ԫ�ص�λ�� */
    *e = *p;                               /*  ��ɾ��Ԫ�ص�ֵ����e */
    q = L->elem + L->length - 1;                /*  ��βԪ�ص�λ�� */
    for (++p; p <= q; ++p) *(p - 1) = *p;     /*  ��ɾ��Ԫ��֮���Ԫ������ */
    --L->length;                           /*  ����1 */
    return OK;
} /*  ListDelete_Sq */

int LocateElem_Sq(SqList L, ElemType e,Status(*compare)(ElemType, ElemType)) 
{   /*  �㷨2.6 */
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
  
    for (int i = 0; i < strlen(e.StuNum); i++)
    {
     if ( e.StuNum[i] == e1.StuNum[i])
        {
            return OK;
        }
     else
     {
         return ERROR;
     }
    }
   
}