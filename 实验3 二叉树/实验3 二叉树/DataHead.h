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

/*定义线性表内的元素类型为字符类型*/
typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;   /*左右孩子指针*/
} BiTNode, * BiTree;              /*结点类型*/

/*函数声明*/
void CreateBiTree(BiTree* T);   /*构造二叉链表* 算法6.4/
Status PrintChar(TElemType e);   /*Visit 函数*/
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)); /*前序遍历二叉树*/
void  InOrderTraverse(BiTree T); /*中序遍历二叉树简单写法*/
void Postorder(BiTree T);      /*后序遍历二叉树*/
int nodes(BiTree T);           /*计算总结点数*/
int leafs(BiTree T);           /*计算总叶子数*/
void swap(BiTree T);        /*交换左右子树*/
int depth(BiTree T);     /*计算二叉树的深度*/

void CreateBiTree(BiTree* T)       /* P131 算法6.4*/
{
    //按照先序次序输入二叉树中结点的值(一个字符)，空格字符表示空树
    //构造二叉链表表示的二叉树T
    char ch;
    scanf_s("%c", &ch, sizeof(ch)); 
//    getchar();
    if (ch =='#') *T = NULL;//二叉树类型指针为NULL  
    else {
        if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        (*T)->data = ch; //数据域为字符ch
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

Status PrintChar(TElemType e)  //TElem Type是char类型
{   /*Visit 函数*/
    printf("%c", e);
    return OK;
}

/*前序遍历二叉树*/
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{  /* P129 算法6.1*/
    if (T) {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild, Visit))
                if (PreOrderTraverse(T->rchild, Visit)) return OK;
        return ERROR;
    }
    else return OK;

}


/*中序遍历二叉树的简单写法 */
void  InOrderTraverse(BiTree T)
{
    if (T) {
        InOrderTraverse(T->lchild);
        printf("%c", T->data);
        InOrderTraverse(T->rchild);
    }

}


/*后序遍历二叉树*/
void Postorder(BiTree T)
{
    if (T) {
        /*请补充代码*/
        Postorder(T->lchild);
        Postorder(T->rchild);
        printf("%c", T->data);
    }
}

/*计算总结点数*/
int nodes(BiTree T)
{
    if (T)
        return(nodes(T->lchild) + nodes(T->rchild) + 1);
    else
        return(0);

}



/*计算总叶子数*/
int leafs(BiTree T)
{
    if (T == NULL)return(0);
    else {
        if (T->lchild == NULL && T->rchild == NULL)
            return(1);
        else return(leafs(T->lchild) + leafs(T->rchild));
    }

}


/*交换左右子树*/
void swap(BiTree T)
{
    BiTree p;
    if (T) {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
        swap(T->lchild);
        swap(T->rchild);
    }
}



/*计算二叉树的深度或者称为高度*/
int depth(BiTree T) {
    int hl, hr, max;
    if (T) {
        if (T->lchild == NULL && T->rchild == NULL) return 1;
        else {
            hl = depth(T->lchild);
            hr = depth(T->rchild);
            max = (hl > hr) ? hl : hr;
            return   max + 1;
        }
    }
    else return 0;
}



/*结点赋值
     叶结点的值为3
     只有左孩子或右孩子的结点则其值分别等于左孩子或右孩子的值
     左、右孩子均有的结点，则其值等于左、右孩子结点的值之和
*/
int ChangeValue(BiTree T)
{
    if (T) {
        if (T->lchild == NULL && T->rchild == NULL)  T->data = 3;
        if (T->lchild != NULL && T->rchild == NULL)  T->data = T->lchild->data;
        if (T->lchild == NULL && T->rchild != NULL)  T->data = T->rchild->data;
        if (T->lchild != NULL && T->rchild != NULL)  T->data = T->lchild->data + T->rchild->data;

        /*请补充代码*/
        return T->data;
    }
}