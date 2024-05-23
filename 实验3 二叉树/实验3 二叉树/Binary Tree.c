#include<stdlib.h>
#include<stdio.h>
#include"DataHead.h"
/*
1、	输入二叉树的先序序列字符，建立二叉链表。注意：输入时，必须加入虚结点以示空指针的位置；
        假设虚结点输入时用空格字符表示。
2、	按先序、中序和后序遍历二叉树
3、	求二叉树结点总数，观察输出结果。
4、	求二叉树叶子数，观察输出结果。
5、	求二叉树的深度（或称高度），观察输出结果。
6、	交换二叉树的左右子树
7、	在主函数中设计一个简单的菜单，分别调试上述算法。
*/

int main()
{
    int k;      /* k ，菜单控制变量*/
    char ch;  //输入字符 ch
    BiTNode bnode; //二叉树结构体 BiTNode 类型变量 bnode
    BiTree tree=&bnode; //指向二叉树结构体 BiTNode 指针类型 BiTree 的指针 tree 
    do {

        printf("\n ============= 实验三：二叉树 ==============\n");
        printf("\n        1.输入二叉树的先序序列，#号代表虚结点\n");
        printf("\n        2.先序遍历二叉树\n");
        printf("\n        3.中序遍历二叉树\n");
        printf("\n        4.后序遍历二叉树\n");
        printf("\n        5.求二叉树叶子数.\n");
        printf("\n        6.求二叉树的深度.\n");
        printf("\n        7.求二叉树的总结点数.\n");
        printf("\n        8.交换二叉树的左右子树.\n");
        printf("\n        9.结点赋值.\n");
        printf("\n        0	退出程序.");
        printf("\n=====================================");
        printf("\n     请输入您的选择（1,2,3,4,5,6,7,0)\n");
        scanf_s("%d", &k);
        getchar();
        switch (k)
        {
        case 1: {
            printf("\n1.输入二叉树的先序序列，空格代表虚结点\n");
            CreateBiTree(&tree);

        }break;
        case 2: {
            printf("\n先序遍历二叉树的结果为\n");
            PreOrderTraverse(tree, PrintChar);
        }break;
        case 3: {
            printf("\n中序遍历二叉树的结果为\n");
            InOrderTraverse(tree);
        }break;

        case 4: {
            printf("后序遍历二叉树的结果为\n");
            Postorder(tree);
        };  break;

        case 5:
        {    
            int leaf = leafs(tree);
            printf("二叉树的叶子数为:%d",leaf);
        };  break;
        case 6:
        {
            int dep = depth(tree);
            printf("二叉树的深度为%d",dep);

        };  break;
        case 7:
        {
            int node = nodes(tree);
            printf("二叉树的总结点个数为:%d",node);
           

        };  break;
        case 8:
        {
            printf("交换二叉树的左右子树\n");
            swap(tree);

        };  break;
        case 9:
        {
            printf("结点赋值\n");
            ChangeValue(tree);
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