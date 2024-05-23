#include"DataHead.h"
#include<stdio.h>
/*主函数*/

int main()
{
    int i, k,n;     
    /* k ，菜单控制变量 
       n  , 线性表的元素个数
       i ,   插入的位置
    */
    ElemType e, x;      //整形元素 e,x
    char ch;   //输入字符 ch 
    SqList L;     //线性表结构体  SqList 类型变量 L
    SqList* p;     //线性表结构体 SqList指针类型变量 p
    p = &L;/*p指向 L*/
    do {

        printf("\n========实验一：线性表 ===============");
        printf("\n        1.建立线性表");
        printf("\n        2.插入元素");
        printf("\n        3.删除元素");
        printf("\n        4.查找元素");
        printf("\n        0.结束程序运行");
        printf("\n=====================================");
        printf("\n        请输入您的选择（1,2,3,4,0)\n");

        scanf_s("%d", &k,sizeof(k));
        switch (k)
        {
        case 1: {
           n = InitList_Sq(p);
            printf("\n请输入线性表元素个数，并依次输入整数类型的元素值\n");
            scanf_s("%d", &n,sizeof(n));
            for (i = 1; i <= n; i++) 
            {
                 scanf_s("%d", &e,sizeof(e));
                ListInsert_Sq(p, i, e);  /*也可以不处理函数返回值*/
            }
            Out_List(L);
        }break;
        case 2: 
        { 
            printf("\n请输入插入位置 i 及  整数元素e的值\n");
            scanf_s("%d%d", &n, &e);
            ListInsert_Sq(p, n, e);
            Out_List(L);
        }break;
        case 3:
        { 
          printf("\n请输入删除位置 i\n");
        scanf_s("%d", &n);
        ListDelete_Sq(p, n, &e);
        Out_List(L);
        }break;
        case 4:
        {

            printf("\n请输入查找的元素的 值 \n");
            ElemType e1;
            scanf_s("%d", &e1);
            int i = LocateElem_Sq(L, e1, compare);
            printf("这是第%d个元素\n", i);

        };  break;
        case 0: { 
            return 0; }; break;
        }
    } while (k != 0);
    printf("\n       按回车键，返回…\n");
    ch = getchar();
    return 0;
}
