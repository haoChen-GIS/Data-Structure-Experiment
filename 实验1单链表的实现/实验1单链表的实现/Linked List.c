/*�����c���Գ�������˳��洢��ʽʵ�����й��ܣ�
���ݼ����������ݽ���һ�����Ա�����������Ա�
Ȼ�������Ļ�˵���ѡ�񣬿��Խ������ݵĲ��롢ɾ�������ң�
���ڲ����ɾ�����ݺ���������Ա�
�������Ļ�˵���ѡ�������ť�����ɽ�����������С�

�ο�˳�����ɵ�����Ļ������ܣ��㷨2.8-�㷨2.11��
*/
#include"DataHead.h"
#include<stdio.h>

int main(){
    int i, k, n;    
    /* k ���˵����Ʊ���
        i ,   ����λ��
        n,   ������Ԫ�ظ���
    */
    ElemType e;               //����Ԫ��e 
    char ch;                     //�����ַ�ch
    LNode L;                 //������ṹ��LNode���ͱ��� L  
    LinkList p=NULL;    //ָ��LNodeָ������LinkList��ָ�����p
    do {

        printf("\n == ʵ��һ�������� ==");
        printf("\n        1.����������");
        printf("\n        2.����Ԫ��");
        printf("\n        3.ɾ��Ԫ��");
        printf("\n        4.����Ԫ��");
        printf("\n        0.������������");
        printf("\n=====================================");
        printf("\n        ����������ѡ��1,2,3,4,0)\n");

        scanf_s("%d", &k, sizeof(k));
        switch (k)
        {
        case 1: {
            printf("\n�����뵥����Ԫ�ظ������������������͵�Ԫ��ֵ\n");
            scanf_s("%d", &n, sizeof(n));
            CreateList_L(&p, n);
            PrintList(p);
        }break;
        case 2: {
               printf("\n���������λ�� i ��  ����Ԫ��e��ֵ\n");
               scanf_s("%d\n%d", &i, &e);
               ListInsert_L(p, i, e);
               PrintList(p);
        }break;
        case 3:
        {
                       printf("\n������ɾ��λ�� i\n");
                       scanf_s("%d", &i);
                       ListDelete_L(p, i, &e);
                        PrintList(p);
        }break;
        case 4:
        {

            printf("\n��������ҵ�Ԫ�ص�λ�� \n");
            scanf_s("%d", &i);
            if (GetElem_L(p, i, &e))
            {
                printf("Ԫ�ص�ֵΪ%d\n", e);

            }
            else
                printf("\n����ʧ��");
         
        };  break;
        case 0: {
            printf("�������н�����\n");
            return 0;
        }; break;

        }

    } while (k != 0);
    printf("\n       ���س��������ء�\n");
    ch = getchar();
}
