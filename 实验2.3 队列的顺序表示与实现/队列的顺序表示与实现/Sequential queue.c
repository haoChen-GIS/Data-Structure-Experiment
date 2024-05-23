#include"DataHead.h"
#include<stdio.h>

int main()
{
        SqQueue Q;
        QElemType e;     //整形元素e
        int x, k, n;     
        /* 
        x， 队内的元素
        k ，菜单控制变量
        n,   队内的元素个数
        */    
        char ch;
        do {

            printf("\n========实验二：栈和队列 ===============");
            printf("\n        1.建立队列：构造一个空队列");
            printf("\n        2.入队，插入元素");
            printf("\n        3.出队，删除元素");
            printf("\n        4.取队顶元素");
            printf("\n        5.输出显示队内元素，从队首到队尾");
            printf("\n        0.结束程序运行");
            printf("\n=====================================");
            printf("\n        请输入您的选择（1,2,3,4,0)\n");
            scanf_s("%d", &k);
            switch (k)
            {
            case 1: {
                printf("队列初始化");
                InitQueue(&Q);
         
            }break;
            case 2:
            {
                printf("请输入要入队元素的个数，并依次输入元素\n");
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
                    printf("出队元素为：%d\n", x);
                TraverseQueue(Q);
            }break;
            case 4:
            {
                x = GetHead(Q);
                if (x != -1)
                    printf("队头元素为：%d\n", x);

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
                printf("输入的选择有误，请重新输入\n");
            }
        } while (k != 0);
        ch = getchar();
 
}