#include"DataHead.h";
#include<stdio.h>
int main() {
    int i, k, n;    
    /* k ���˵����Ʊ���
      i ,   ����λ��
      n,   ջ��Ԫ�ظ���
      */
    LinkStack L;   //ջ����ʽ�洢�ṹ��LinkStack ���ͱ���L
    SElemType e; //����Ԫ�� e
    char ch;          //�����ַ� ch
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
            InitStack(&L);
            int n;
            printf("%��������ջԪ�صĸ�������������������Ԫ�ص�ֵ\n");
            scanf_s("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf_s("%d", &e);
                Push(&L, e);  
            }
            Out_Stack(&L);
        }break;
        case 2:
        {
           
            printf("������Ҫ��ջ��Ԫ��\n");
            scanf_s("%d", &e);
            Push(&L, e);
            Out_Stack(&L);
        }break;
        case 3:
        {
            Pop(&L, &e);//��ջ
            Out_Stack(&L);//��ջ�׵�ջ���г�ջ��Ԫ��
            /* �˴�Ҫ�󲹳���롭��*/
        }break;
        case 4:
        {
           
            printf("ջ��Ԫ��Ϊ%d", GetTop(&L, &e));
            /* �˴�Ҫ�󲹳���롭��*/

        }; break;
        case 5:
        {
            Out_Stack(&L);
        }; break;
        case 0:
        {
            exit(0);
        }
        }
    } while (k != 0);
    ch = getchar();
  
 
    return 0;
}
