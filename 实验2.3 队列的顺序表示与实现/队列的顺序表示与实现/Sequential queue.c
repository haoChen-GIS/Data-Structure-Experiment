#include"DataHead.h"
#include<stdio.h>

int main()
{
        SqQueue Q;
        QElemType e;     //����Ԫ��e
        int x, k, n;     
        /* 
        x�� ���ڵ�Ԫ��
        k ���˵����Ʊ���
        n,   ���ڵ�Ԫ�ظ���
        */    
        char ch;
        do {

            printf("\n========ʵ�����ջ�Ͷ��� ===============");
            printf("\n        1.�������У�����һ���ն���");
            printf("\n        2.��ӣ�����Ԫ��");
            printf("\n        3.���ӣ�ɾ��Ԫ��");
            printf("\n        4.ȡ�Ӷ�Ԫ��");
            printf("\n        5.�����ʾ����Ԫ�أ��Ӷ��׵���β");
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
                printf("������Ҫ���Ԫ�صĸ���������������Ԫ��\n");
                scanf_s("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    scanf_s("%d", &e);
                    EnQueue(&Q, e);
                }
                TraverseQueue(Q);
            }break;
            case 3:
            {
                x = DeQueue(&Q,&e);
                if (x != -1)
                    printf("����Ԫ��Ϊ��%d\n", x);
                TraverseQueue(Q);
            }break;
            case 4:
            {
                x = GetHead(Q);
                if (x != -1)
                    printf("��ͷԪ��Ϊ��%d\n", x);

            }; break;
            case 5:
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
 
}