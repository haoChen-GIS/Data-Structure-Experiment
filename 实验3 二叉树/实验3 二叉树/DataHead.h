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

/*�������Ա��ڵ�Ԫ������Ϊ�ַ�����*/
typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;   /*���Һ���ָ��*/
} BiTNode, * BiTree;              /*�������*/

/*��������*/
void CreateBiTree(BiTree* T);   /*�����������* �㷨6.4/
Status PrintChar(TElemType e);   /*Visit ����*/
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)); /*ǰ�����������*/
void  InOrderTraverse(BiTree T); /*���������������д��*/
void Postorder(BiTree T);      /*�������������*/
int nodes(BiTree T);           /*�����ܽ����*/
int leafs(BiTree T);           /*������Ҷ����*/
void swap(BiTree T);        /*������������*/
int depth(BiTree T);     /*��������������*/

void CreateBiTree(BiTree* T)       /* P131 �㷨6.4*/
{
    //���������������������н���ֵ(һ���ַ�)���ո��ַ���ʾ����
    //������������ʾ�Ķ�����T
    char ch;
    scanf_s("%c", &ch, sizeof(ch)); 
//    getchar();
    if (ch =='#') *T = NULL;//����������ָ��ΪNULL  
    else {
        if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        (*T)->data = ch; //������Ϊ�ַ�ch
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

Status PrintChar(TElemType e)  //TElem Type��char����
{   /*Visit ����*/
    printf("%c", e);
    return OK;
}

/*ǰ�����������*/
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{  /* P129 �㷨6.1*/
    if (T) {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild, Visit))
                if (PreOrderTraverse(T->rchild, Visit)) return OK;
        return ERROR;
    }
    else return OK;

}


/*��������������ļ�д�� */
void  InOrderTraverse(BiTree T)
{
    if (T) {
        InOrderTraverse(T->lchild);
        printf("%c", T->data);
        InOrderTraverse(T->rchild);
    }

}


/*�������������*/
void Postorder(BiTree T)
{
    if (T) {
        /*�벹�����*/
        Postorder(T->lchild);
        Postorder(T->rchild);
        printf("%c", T->data);
    }
}

/*�����ܽ����*/
int nodes(BiTree T)
{
    if (T)
        return(nodes(T->lchild) + nodes(T->rchild) + 1);
    else
        return(0);

}



/*������Ҷ����*/
int leafs(BiTree T)
{
    if (T == NULL)return(0);
    else {
        if (T->lchild == NULL && T->rchild == NULL)
            return(1);
        else return(leafs(T->lchild) + leafs(T->rchild));
    }

}


/*������������*/
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



/*�������������Ȼ��߳�Ϊ�߶�*/
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



/*��㸳ֵ
     Ҷ����ֵΪ3
     ֻ�����ӻ��Һ��ӵĽ������ֵ�ֱ�������ӻ��Һ��ӵ�ֵ
     ���Һ��Ӿ��еĽ�㣬����ֵ�������Һ��ӽ���ֵ֮��
*/
int ChangeValue(BiTree T)
{
    if (T) {
        if (T->lchild == NULL && T->rchild == NULL)  T->data = 3;
        if (T->lchild != NULL && T->rchild == NULL)  T->data = T->lchild->data;
        if (T->lchild == NULL && T->rchild != NULL)  T->data = T->rchild->data;
        if (T->lchild != NULL && T->rchild != NULL)  T->data = T->lchild->data + T->rchild->data;

        /*�벹�����*/
        return T->data;
    }
}