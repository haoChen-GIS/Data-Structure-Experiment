#include"DataHead.h"
#include<stdio.h>
/*������*/

int main()
{
    int i, k,n;     
    /* k ���˵����Ʊ��� 
       n  , ���Ա��Ԫ�ظ���
       i ,   �����λ��
    */
    ElemType e, x;      //����Ԫ�� e,x
    char ch;   //�����ַ� ch 
    SqList L;     //���Ա�ṹ��  SqList ���ͱ��� L
    SqList* p;     //���Ա�ṹ�� SqListָ�����ͱ��� p
    p = &L;/*pָ�� L*/
    do {

        printf("\n========ʵ��һ�����Ա� ===============");
        printf("\n        1.�������Ա�");
        printf("\n        2.����Ԫ��");
        printf("\n        3.ɾ��Ԫ��");
        printf("\n        4.����Ԫ��");
        printf("\n        0.������������");
        printf("\n=====================================");
        printf("\n        ����������ѡ��1,2,3,4,0)\n");

        scanf_s("%d", &k,sizeof(k));
        switch (k)
        {
        case 1: {
           n = InitList_Sq(p);
            printf("\n���������Ա�Ԫ�ظ����������������������͵�Ԫ��ֵ\n");
            scanf_s("%d", &n,sizeof(n));
            for (i = 1; i <= n; i++) 
            {
                 scanf_s("%d", &e,sizeof(e));
                ListInsert_Sq(p, i, e);  /*Ҳ���Բ�����������ֵ*/
            }
            Out_List(L);
        }break;
        case 2: 
        { 
            printf("\n���������λ�� i ��  ����Ԫ��e��ֵ\n");
            scanf_s("%d%d", &n, &e);
            ListInsert_Sq(p, n, e);
            Out_List(L);
        }break;
        case 3:
        { 
          printf("\n������ɾ��λ�� i\n");
        scanf_s("%d", &n);
        ListDelete_Sq(p, n, &e);
        Out_List(L);
        }break;
        case 4:
        {

            printf("\n��������ҵ�Ԫ�ص� ֵ \n");
            ElemType e1;
            scanf_s("%d", &e1);
            int i = LocateElem_Sq(L, e1, compare);
            printf("���ǵ�%d��Ԫ��\n", i);

        };  break;
        case 0: { 
            return 0; }; break;
        }
    } while (k != 0);
    printf("\n       ���س��������ء�\n");
    ch = getchar();
    return 0;
}
