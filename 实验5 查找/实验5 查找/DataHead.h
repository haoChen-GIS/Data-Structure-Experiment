#pragma once
#include <corecrt_malloc.h>
#include<stdio.h>
/*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //������
#define OVERFLOW -2   //���

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;


/*����������ʽ�洢��ʾ*/
typedef int TElemType;      /*���û������ʵ����������*/

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;   /*���Һ���ָ��*/
} BiTNode, * BiTree;              /*�������*/



typedef int KeyType;       /*����������ʹ����������*/
typedef int ElemType;       /*����������ʹ����������*/


void Inorder(BiTree T); /*�������������*/
Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree* p);
Status InsertBST(BiTree* T, ElemType e);
Status DeleteBST(BiTree* T, KeyType key);
Status Delete(BiTree* p);
Status EQ(KeyType key1, KeyType key2);
Status LT(KeyType key1, KeyType key2);

/*��������������ļ�д�� */
void Inorder(BiTree T)
{
    if (T) {
        Inorder(T->lchild);
        printf("%d", T->data);
        Inorder(T->rchild);
    }

}


Status EQ(KeyType key1, KeyType key2) {
    if (key1 == key2) return TRUE;
    else return FALSE;
}
Status LT(KeyType key1, KeyType key2) {
    if (key1 < key2) return TRUE;
    else return FALSE;
}


Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree* p) {
    /*  �㷨9.5(b) */
    /*  �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ� */
    /*  �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE�� */
    /*  ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE�� */
    /*  ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
    if (!T) { *p = f;  return FALSE; }                     /*  ���Ҳ��ɹ� */
    else if (EQ(key, T->data)) { *p = T;  return TRUE; } /*  ���ҳɹ� */
    else if (LT(key, T->data))
        return SearchBST(T->lchild, key, T, p);  /*  ���������м������� */
    else
        return SearchBST(T->rchild, key, T, p);  /*  ���������м������� */
} /*  SearchBST */

Status InsertBST(BiTree* T, ElemType e) {  /*  �㷨9.6 */
  /*  ������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ�� */
  /*  ����e������TRUE�����򷵻�FALSE */
    BiTree p, s;
    if (!SearchBST(*T, e, NULL, &p)) {   /*  ���Ҳ��ɹ� */
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;  s->lchild = s->rchild = NULL;
        if (!p) *T = s;        /*  ���� s Ϊ�µĸ���� */
        else if (LT(e, p->data)) p->lchild = s; /*  ����sΪ���� */
        else p->rchild = s;   /*  ���� s Ϊ�Һ��� */
        return TRUE;
    }
    else return FALSE;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
} /*  Insert BST */
Status DeleteBST(BiTree* T, KeyType key) { /*  �㷨9.7  */
  /*  ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ�� */
  /*  ��ɾ��������Ԫ�ؽ��p��������TRUE�����򷵻�FALSE */
    if (!(*T)) return FALSE;       /*  �����ڹؼ��ֵ���key������Ԫ�� */
    else {
        if (EQ(key, (*T)->data))  /*  �ҵ��ؼ��ֵ���key������Ԫ�� */
            return Delete(T);
        else if (LT(key, (*T)->data)) return DeleteBST(&((*T)->lchild), key);
        else return DeleteBST(&((*T)->rchild), key);
    }
} /*  DeleteBST */
Status Delete(BiTree* p) {  /*  �㷨9.8 */
  /*  �Ӷ�����������ɾ�����p�����ؽ�������������� */
    BiTree q, s;
    if (!((*p)->rchild)) {  /*  ����������ֻ���ؽ����������� */
        q = *p;  *p = (*p)->lchild;  free(q);
    }
    else if (!((*p)->lchild)) {  /*  ֻ���ؽ����������� */
        q = *p;  *p = (*p)->rchild;  free(q);
    }
    else {  /*  �������������� */
        q = *p;  s = (*p)->lchild;
        while (s->rchild)   /*  ת��Ȼ�����ҵ���ͷ */
        {
            q = s;  s = s->rchild;
        }
        (*p)->data = s->data;                  /*  sָ��ɾ����"���" */
        if (q != *p) q->rchild = s->lchild;  /*  �ؽ�*q�������� */
        else q->lchild = s->lchild;         /*  �ؽ�*q�������� */
        free(s);
    }
    return TRUE;
} /*  Delete */


