#include<stdio.h>
#include"DataHead.h"

int main()
{
        int i, k, n;    
        /* k ���˵����Ʊ���
       i ,   ����λ��
       n,   ջ��Ԫ�ظ���
       */
        SElemType e, x;  //����Ԫ�� e,x
        char ch;               //�����ַ�ch
        SqStack S;      //ջ�ṹ��SqStack���ͱ���L
        SqStack* p;    //ջ�ṹ��SqStackָ�����ͱ���p
        p = &S;/*pָ�� L*/
        do {

            printf("\n========ʵ�����ջ�Ͷ��� ===============");
            printf("\n        1.����ջ������һ����ջ,������Ԫ��");
            printf("\n        2.��ջ������Ԫ��");
            printf("\n        3.��ջ��ɾ��Ԫ��");
            printf("\n        4.ȡջ��Ԫ��");
            printf("\n        5.�����ʾջ��Ԫ�أ���ջ�׵�ջ��");
            printf("\n        0.������������");
            printf("\n=====================================");
            printf("\n        ����������ѡ��1,2,3,4,0)\n");

            scanf_s("%d", &k);
            switch (k)
            {
            case 1: {
                n = InitStack(p);
                printf("\n��������ջԪ�ظ����������������������͵�Ԫ��ֵ\n");
                scanf_s("%d", &n);
                for (i = 1; i <= n; i++) {
                    scanf_s("%d", &e);
                    Push(p, e);  /*Ҳ���Բ�����������ֵ*/
                }
                Out_Stack(S);
            }break;
            case 2: 
            {
                /* �˴�Ҫ�󲹳���롭��*/
                printf("������Ҫ��ջ��Ԫ��\n");
                scanf_s("%d", &e);
                Push(&S, e);
            }break;
            case 3: 
            { 
                Pop(&S, &e);//��ջ
                Out_Stack(S);//��ջ�׵�ջ���г�ջ��Ԫ��
                /* �˴�Ҫ�󲹳���롭��*/
            }break;
            case 4:
            {
                GetTop(S, &e);
                printf("ջ��Ԫ��Ϊ%d", e);
                /* �˴�Ҫ�󲹳���롭��*/

            }; break;
            case 5: 
            {
                Out_Stack(S);
            }; break;
            case 0:
            {
                exit(0);
            }
            }
        } while (k != 0);
        ch = getchar();
}
