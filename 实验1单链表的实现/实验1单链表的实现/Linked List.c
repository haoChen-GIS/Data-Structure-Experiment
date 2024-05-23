/*请编制c语言程序，利用顺序存储方式实现下列功能：
根据键盘输入数据建立一个线性表，并输出该线性表；
然后根据屏幕菜单的选择，可以进行数据的插入、删除、查找，
并在插入或删除数据后，再输出线性表；
最后在屏幕菜单中选择结束按钮，即可结束程序的运行。

参考顺序表，完成单链表的基本功能（算法2.8-算法2.11）
*/
#include"DataHead.h"
#include<stdio.h>

int main(){
    int i, k, n;    
    /* k ，菜单控制变量
        i ,   插入位置
        n,   单链表元素个数
    */
    ElemType e;               //整形元素e 
    char ch;                     //输入字符ch
    LNode L;                 //单链表结构体LNode类型变量 L  
    LinkList p=NULL;    //指向LNode指针类型LinkList的指针变量p
    do {

        printf("\n == 实验一：单链表 ==");
        printf("\n        1.建立单链表");
        printf("\n        2.插入元素");
        printf("\n        3.删除元素");
        printf("\n        4.查找元素");
        printf("\n        0.结束程序运行");
        printf("\n=====================================");
        printf("\n        请输入您的选择（1,2,3,4,0)\n");

        scanf_s("%d", &k, sizeof(k));
        switch (k)
        {
        case 1: {
            printf("\n请输入单链表元素个数，并输入整数类型的元素值\n");
            scanf_s("%d", &n, sizeof(n));
            CreateList_L(&p, n);
            PrintList(p);
        }break;
        case 2: {
               printf("\n请输入插入位置 i 及  整数元素e的值\n");
               scanf_s("%d\n%d", &i, &e);
               ListInsert_L(p, i, e);
               PrintList(p);
        }break;
        case 3:
        {
                       printf("\n请输入删除位置 i\n");
                       scanf_s("%d", &i);
                       ListDelete_L(p, i, &e);
                        PrintList(p);
        }break;
        case 4:
        {

            printf("\n请输入查找的元素的位置 \n");
            scanf_s("%d", &i);
            if (GetElem_L(p, i, &e))
            {
                printf("元素的值为%d\n", e);

            }
            else
                printf("\n查找失败");
         
        };  break;
        case 0: {
            printf("程序运行结束！\n");
            return 0;
        }; break;

        }

    } while (k != 0);
    printf("\n       按回车键，返回…\n");
    ch = getchar();
}
