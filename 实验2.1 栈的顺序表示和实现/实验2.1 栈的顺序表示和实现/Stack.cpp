#include<stdio.h>
#include"DataHead.h"

int main()
{
        int i, k, n;    
        /* k ，菜单控制变量
       i ,   插入位置
       n,   栈内元素个数
       */
        SElemType e, x;  //整形元素 e,x
        char ch;               //输入字符ch
        SqStack S;      //栈结构体SqStack类型变量L
        SqStack* p;    //栈结构体SqStack指针类型变量p
        p = &S;/*p指向 L*/
        do {

            printf("\n========实验二：栈和队列 ===============");
            printf("\n        1.建立栈：构造一个空栈,并插入元素");
            printf("\n        2.入栈，插入元素");
            printf("\n        3.出栈，删除元素");
            printf("\n        4.取栈顶元素");
            printf("\n        5.输出显示栈内元素，从栈底到栈顶");
            printf("\n        0.结束程序运行");
            printf("\n=====================================");
            printf("\n        请输入您的选择（1,2,3,4,0)\n");

            scanf_s("%d", &k);
            switch (k)
            {
            case 1: {
                n = InitStack(p);
                printf("\n请输入入栈元素个数，并依次输入整数类型的元素值\n");
                scanf_s("%d", &n);
                for (i = 1; i <= n; i++) {
                    scanf_s("%d", &e);
                    Push(p, e);  /*也可以不处理函数返回值*/
                }
                Out_Stack(S);
            }break;
            case 2: 
            {
                /* 此处要求补充代码……*/
                printf("请输入要入栈的元素\n");
                scanf_s("%d", &e);
                Push(&S, e);
            }break;
            case 3: 
            { 
                Pop(&S, &e);//出栈
                Out_Stack(S);//从栈底到栈顶列出栈内元素
                /* 此处要求补充代码……*/
            }break;
            case 4:
            {
                GetTop(S, &e);
                printf("栈顶元素为%d", e);
                /* 此处要求补充代码……*/

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
