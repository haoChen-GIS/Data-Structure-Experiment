#include"DataHead.h"
#include<stdio.h>
/*
��1��	��ʼ��������������
��2��	��������
��3��	��������
��4��	����������
*/

int main()
{
    LinkQueue Q;
    QElemType e ;
    int x, k, n;     
    /*
     x ,�����ڵ�Ԫ��   
     k ���˵����Ʊ���
    n,�����ڵ�Ԫ�ظ���
    */
    char ch;  //�����ַ� ch
    do {

        printf("\n========ʵ�����ջ�Ͷ��� ===============");
        printf("\n        1.����������");
        printf("\n        2.�������У�����Ԫ��");
        printf("\n        3.�������У�ɾ��Ԫ��");
        printf("\n        4.�����ʾ����Ԫ�أ��Ӷ�sho��ջ��");
        printf("\n        0.������������");
        printf("\n=====================================");
        printf("\n        ����������ѡ��1,2,3,4,0)\n");
        scanf_s("%d", &k);
        switch (k)
        {
        case 1: {
            printf("���г�ʼ��");
            InitQueue(&Q);

        }break;
        case 2:
        {
            printf("���������Ԫ�صĸ�����");
            int n, x;
            scanf_s("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("�������%d��Ԫ�أ�", i + 1);
                scanf_s("%d", &x);
                EnQueue(&Q, x);
            }
            printf("�������У�");
            TraverseQueue(Q);  //������ǰ�Ķ���Ԫ��
        }break;
        case 3:
        {
            DeQueue(&Q, &e);
            printf("����Ԫ��Ϊ��%d\n",e );
            printf("�������У�");
            TraverseQueue(Q);
        }break;
        case 4:
        {
            TraverseQueue(Q);
        }; break;
        case 0:
        {
            exit(0);
        }
        default:
            printf("�����ѡ����������������\n");
        }
    } while (k != 0);
    ch = getchar();
    return 0;
   
}