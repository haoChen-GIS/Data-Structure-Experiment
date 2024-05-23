#include"DataHead.h"
#include<stdio.h>
/*
（1）	初始化并建立链队列
（2）	入链队列
（3）	出链队列
（4）	遍历链队列
*/

int main()
{
    LinkQueue Q;
    QElemType e ;
    int x, k, n;     
    /*
     x ,队列内的元素   
     k ，菜单控制变量
    n,队列内的元素个数
    */
    char ch;  //输入字符 ch
    do {

        printf("\n========实验二：栈和队列 ===============");
        printf("\n        1.建立链队列");
        printf("\n        2.入链队列，插入元素");
        printf("\n        3.出链队列，删除元素");
        printf("\n        4.输出显示队内元素，从队sho到栈顶");
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
            printf("请输入入队元素的个数：");
            int n, x;
            scanf_s("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("请输入第%d个元素：", i + 1);
                scanf_s("%d", &x);
                EnQueue(&Q, x);
            }
            printf("遍历队列：");
            TraverseQueue(Q);  //遍历当前的队列元素
        }break;
        case 3:
        {
            DeQueue(&Q, &e);
            printf("出队元素为：%d\n",e );
            printf("遍历队列：");
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
            printf("输入的选择有误，请重新输入\n");
        }
    } while (k != 0);
    ch = getchar();
    return 0;
   
}