/*请编制c语言程序，利用顺序存储方式实现下列功能：
根据键盘输入数据建立一个线性表，并输出该线性表；
然后根据屏幕菜单的选择，可以进行数据的插入、删除、查找，
并在插入或删除数据后，再输出线性表；
最后在屏幕菜单中选择结束按钮，即可结束程序的运行。

参考顺序表，完成单链表的基本功能（算法2.8-算法2.11）
*/
#include<stdio.h>
#include"Datahead.h"

int main()
{
    int i, k, n;     /* k ，菜单控制变量*/
    ElemType e, x;
    char ch;
    SqList L;
    SqList* p;
    //system("graftabl 936");/*调用MS_DOS中文支持*/
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

        scanf_s("%d", &k);
        switch (k)
        {
        case 1:
        {
          n= InitList_Sq(p);
            printf("\n请输入线性表元素个数，并依次输入元素的姓名 学号 成绩\n");
            scanf_s("%d", &n);
            getchar();
            for (i = 1; i <= n; i++) 
            { 
                gets(e.Name, 20, stdin);
                gets(e.StuNum, 20, stdin);
                scanf_s("%d", &e.Score);
                ListInsert_Sq(p, i, e);  /*也可以不处理函数返回值*/
                getchar();
            }
            Out_List(L);
        }break;
        case 2: { printf("\n请输入插入位置 i 以及  元素的姓名 学号 成绩\n");
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
        {  printf("\n请输入删除位置 i\n");    
           scanf_s("%d", &n);
           ListDelete_Sq(p, n, &e);
           Out_List(L);
        }break;

        case 4:
        { 
           
            printf("\n请输入查找的元素的 学号 \n"); 
            ElemType e1 ;
            getchar();
           
            gets(e1.StuNum, 20, stdin);
            int i = LocateElem_Sq(L, e1, compare);
            printf("这是第%d个元素\n", i);
          
        };  break;

        
        case 0: { 
            return 0;
        };
        }
    } while (k != 0);
    printf("\n       按回车键，返回…\n");
    ch = getchar();
	return 0;
}