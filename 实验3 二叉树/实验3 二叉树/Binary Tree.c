#include<stdlib.h>
#include<stdio.h>
#include"DataHead.h"
/*
1��	��������������������ַ���������������ע�⣺����ʱ���������������ʾ��ָ���λ�ã�
        ������������ʱ�ÿո��ַ���ʾ��
2��	����������ͺ������������
3��	�����������������۲���������
4��	�������Ҷ�������۲���������
5��	�����������ȣ���Ƹ߶ȣ����۲���������
6��	��������������������
7��	�������������һ���򵥵Ĳ˵����ֱ���������㷨��
*/

int main()
{
    int k;      /* k ���˵����Ʊ���*/
    char ch;  //�����ַ� ch
    BiTNode bnode; //�������ṹ�� BiTNode ���ͱ��� bnode
    BiTree tree=&bnode; //ָ��������ṹ�� BiTNode ָ������ BiTree ��ָ�� tree 
    do {

        printf("\n ============= ʵ������������ ==============\n");
        printf("\n        1.������������������У�#�Ŵ�������\n");
        printf("\n        2.�������������\n");
        printf("\n        3.�������������\n");
        printf("\n        4.�������������\n");
        printf("\n        5.�������Ҷ����.\n");
        printf("\n        6.������������.\n");
        printf("\n        7.����������ܽ����.\n");
        printf("\n        8.��������������������.\n");
        printf("\n        9.��㸳ֵ.\n");
        printf("\n        0	�˳�����.");
        printf("\n=====================================");
        printf("\n     ����������ѡ��1,2,3,4,5,6,7,0)\n");
        scanf_s("%d", &k);
        getchar();
        switch (k)
        {
        case 1: {
            printf("\n1.������������������У��ո��������\n");
            CreateBiTree(&tree);

        }break;
        case 2: {
            printf("\n��������������Ľ��Ϊ\n");
            PreOrderTraverse(tree, PrintChar);
        }break;
        case 3: {
            printf("\n��������������Ľ��Ϊ\n");
            InOrderTraverse(tree);
        }break;

        case 4: {
            printf("��������������Ľ��Ϊ\n");
            Postorder(tree);
        };  break;

        case 5:
        {    
            int leaf = leafs(tree);
            printf("��������Ҷ����Ϊ:%d",leaf);
        };  break;
        case 6:
        {
            int dep = depth(tree);
            printf("�����������Ϊ%d",dep);

        };  break;
        case 7:
        {
            int node = nodes(tree);
            printf("���������ܽ�����Ϊ:%d",node);
           

        };  break;
        case 8:
        {
            printf("��������������������\n");
            swap(tree);

        };  break;
        case 9:
        {
            printf("��㸳ֵ\n");
            ChangeValue(tree);
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