/*�����c���Գ�������˳��洢��ʽʵ�����й��ܣ�
���ݼ����������ݽ���һ�����Ա�����������Ա�
Ȼ�������Ļ�˵���ѡ�񣬿��Խ������ݵĲ��롢ɾ�������ң�
���ڲ����ɾ�����ݺ���������Ա�
�������Ļ�˵���ѡ�������ť�����ɽ�����������С�

�ο�˳�����ɵ�����Ļ������ܣ��㷨2.8-�㷨2.11��
*/
#include<stdio.h>
#include"Datahead.h"

int main()
{
    int i, k, n;     /* k ���˵����Ʊ���*/
    ElemType e, x;
    char ch;
    SqList L;
    SqList* p;
    //system("graftabl 936");/*����MS_DOS����֧��*/
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

        scanf_s("%d", &k);
        switch (k)
        {
        case 1:
        {
          n= InitList_Sq(p);
            printf("\n���������Ա�Ԫ�ظ���������������Ԫ�ص����� ѧ�� �ɼ�\n");
            scanf_s("%d", &n);
            getchar();
            for (i = 1; i <= n; i++) 
            { 
                gets(e.Name, 20, stdin);
                gets(e.StuNum, 20, stdin);
                scanf_s("%d", &e.Score);
                ListInsert_Sq(p, i, e);  /*Ҳ���Բ�����������ֵ*/
                getchar();
            }
            Out_List(L);
        }break;
        case 2: { printf("\n���������λ�� i �Լ�  Ԫ�ص����� ѧ�� �ɼ�\n");
            scanf_s("%d" ,&n);
            getchar();
            gets(e.Name, 20, stdin);
            gets(e.StuNum, 20, stdin);
            scanf_s("%d", &e.Score);
            
            //scanf_s("%d\n%s\n%s\n%d", &loc, e.Name,e.StuNum ,e.Score);
            ListInsert_Sq(p,n, e);
            Out_List(L);
        }break;
        case 3: 
        {  printf("\n������ɾ��λ�� i\n");    
           scanf_s("%d", &n);
           ListDelete_Sq(p, n, &e);
           Out_List(L);
        }break;

        case 4:
        { 
           
            printf("\n��������ҵ�Ԫ�ص� ѧ�� \n"); 
            ElemType e1 ;
            getchar();
           
            gets(e1.StuNum, 20, stdin);
            int i = LocateElem_Sq(L, e1, compare);
            printf("���ǵ�%d��Ԫ��\n", i);
          
        };  break;

        
        case 0: { 
            return 0;
        };
        }
    } while (k != 0);
    printf("\n       ���س��������ء�\n");
    ch = getchar();
	return 0;
}