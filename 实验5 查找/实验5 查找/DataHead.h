#pragma once
#include <corecrt_malloc.h>
#include<stdio.h>
/*该头文件包含数据结构预定义的常量以及类型*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //不可行
#define OVERFLOW -2   //溢出

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;


/*二叉树的链式存储表示*/
typedef int TElemType;      /*由用户定义的实际数据类型*/

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;   /*左右孩子指针*/
} BiTNode, * BiTree;              /*结点类型*/



typedef int KeyType;       /*二叉排序树使用整形数据*/
typedef int ElemType;       /*二叉排序树使用整形数据*/


void Inorder(BiTree T); /*中序遍历二叉树*/
Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree* p);
Status InsertBST(BiTree* T, ElemType e);
Status DeleteBST(BiTree* T, KeyType key);
Status Delete(BiTree* p);
Status EQ(KeyType key1, KeyType key2);
Status LT(KeyType key1, KeyType key2);

/*中序遍历二叉树的简单写法 */
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
    /*  算法9.5(b) */
    /*  在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素， */
    /*  若查找成功，则指针p指向该数据元素结点，并返回TRUE， */
    /*  否则指针p指向查找路径上访问的最后一个结点并返回FALSE， */
    /*  指针f指向T的双亲，其初始调用值为NULL */
    if (!T) { *p = f;  return FALSE; }                     /*  查找不成功 */
    else if (EQ(key, T->data)) { *p = T;  return TRUE; } /*  查找成功 */
    else if (LT(key, T->data))
        return SearchBST(T->lchild, key, T, p);  /*  在左子树中继续查找 */
    else
        return SearchBST(T->rchild, key, T, p);  /*  在右子树中继续查找 */
} /*  SearchBST */

Status InsertBST(BiTree* T, ElemType e) {  /*  算法9.6 */
  /*  当二叉排序树T中不存在关键字等于e.key的数据元素时， */
  /*  插入e并返回TRUE，否则返回FALSE */
    BiTree p, s;
    if (!SearchBST(*T, e, NULL, &p)) {   /*  查找不成功 */
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;  s->lchild = s->rchild = NULL;
        if (!p) *T = s;        /*  插入 s 为新的根结点 */
        else if (LT(e, p->data)) p->lchild = s; /*  插入s为左孩子 */
        else p->rchild = s;   /*  插入 s 为右孩子 */
        return TRUE;
    }
    else return FALSE;  /*  树中已有关键字相同的结点，不再插入 */
} /*  Insert BST */
Status DeleteBST(BiTree* T, KeyType key) { /*  算法9.7  */
  /*  若二叉排序树T中存在关键字等于key的数据元素时， */
  /*  则删除该数据元素结点p，并返回TRUE；否则返回FALSE */
    if (!(*T)) return FALSE;       /*  不存在关键字等于key的数据元素 */
    else {
        if (EQ(key, (*T)->data))  /*  找到关键字等于key的数据元素 */
            return Delete(T);
        else if (LT(key, (*T)->data)) return DeleteBST(&((*T)->lchild), key);
        else return DeleteBST(&((*T)->rchild), key);
    }
} /*  DeleteBST */
Status Delete(BiTree* p) {  /*  算法9.8 */
  /*  从二叉排序树中删除结点p，并重接它的左或右子树 */
    BiTree q, s;
    if (!((*p)->rchild)) {  /*  右子树空则只需重接它的左子树 */
        q = *p;  *p = (*p)->lchild;  free(q);
    }
    else if (!((*p)->lchild)) {  /*  只需重接它的右子树 */
        q = *p;  *p = (*p)->rchild;  free(q);
    }
    else {  /*  左右子树均不空 */
        q = *p;  s = (*p)->lchild;
        while (s->rchild)   /*  转左，然后向右到尽头 */
        {
            q = s;  s = s->rchild;
        }
        (*p)->data = s->data;                  /*  s指向被删结点的"后继" */
        if (q != *p) q->rchild = s->lchild;  /*  重接*q的右子树 */
        else q->lchild = s->lchild;         /*  重接*q的左子树 */
        free(s);
    }
    return TRUE;
} /*  Delete */


