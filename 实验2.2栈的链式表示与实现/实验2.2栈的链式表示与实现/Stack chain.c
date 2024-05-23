#include"DataHead.h";
#include<stdio.h>
int main() {
    int i, k, n;    
    /* k ，菜单控制变量
      i ,   插入位置
      n,   栈内元素个数
      */
    LinkStack L;   //栈的链式存储结构体LinkStack 类型变量L
    SElemType e; //整形元素 e
    char ch;          //输入字符 ch
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
            InitStack(&L);
            int n;
            printf("%请输入入栈元素的个数，并依次输入整形元素的值\n");
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
           
            printf("请输入要入栈的元素\n");
            scanf_s("%d", &e);
            Push(&L, e);
            Out_Stack(&L);
        }break;
        case 3:
        {
            Pop(&L, &e);//出栈
            Out_Stack(&L);//从栈底到栈顶列出栈内元素
            /* 此处要求补充代码……*/
        }break;
        case 4:
        {
           
            printf("栈顶元素为%d", GetTop(&L, &e));
            /* 此处要求补充代码……*/

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
