#include<stdio.h>
#include"DataHead.h"
/// <summary>
/// 实现二叉排序树上的查找、插入、删除算法。具体实现要求：
///1.	用二叉链表做存储结构，输入键值序列，利用查找、插入算法建立一棵二叉排序树。
///2.	按中序遍历这棵二叉排序树。
///3.	在二叉排序树上插入结点。
///4.	删除二叉排序树上的结点。
/// </summary>
/// <returns></returns>

int main() {

    BiTree T = NULL;
    int n=0;
    ElemType keys[20];   
    //ElemType keys[] = { 5, 3, 8, 2, 4, 1, 7, 9, 6 };
   
    // 输入键值序列建立二叉排序树
    printf("请输入二叉排序树的元素个数\n");
    scanf_s("%d", &n);
    printf("%请依次输入元素的值\n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &keys[i]);
    }

    for (int i = 0; i < n; i++) {
        InsertBST(&T, keys[i]);
    }

    // 中序遍历二叉排序树
    printf("中序遍历结果: ");
    Inorder(T);
    printf("\n");

    // 插入节点
    printf("请输入要插入的结点\n");
    ElemType insertKey = 0;
    scanf_s("%d",&insertKey);
    if (InsertBST(&T, insertKey)) {
        printf("插入节点 %d 后的中序遍历结果: ", insertKey);
        Inorder(T);
        printf("\n");
    }
    else {
        printf("插入节点 %d 失败，已存在相同关键字的节点\n", insertKey);
    }

    // 删除节点
    printf("请输入要删除的结点:\n");
     KeyType deleteKey=0;
     scanf_s("%d",&deleteKey);
    if (DeleteBST(&T, deleteKey)) {
        printf("删除节点 %d 后的中序遍历结果: ", deleteKey);
        Inorder(T);
        printf("\n");
    }
    else {
        printf("删除节点 %d 失败，节点不存在\n", deleteKey);
    }

    return 0;
}