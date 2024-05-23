
#include<stdio.h>
#include"DataHead.h"
/// <summary>
/// 三、	实验内容（2学时）
///建立无向网的邻接矩阵存储并输出，参考程序清单，实现无向图的邻接矩阵表示。
///	建立图的邻接表存储并在此基础上实现图的深度优先遍历和广度优先遍历
///备注：无向图已完成,无向网需要自己建立(参照算法7.2)；
/// 参照算法7.4、 7.5、7.6完成图的深度遍历，广度遍历；
/// 请添加适当的注释.
/// </summary>
/// <returns></returns>

int main() {

	MGraph* p;
	MGraph G;   /*全局变量  图G*/
	ALGraph* A, AL; /*邻接表变量*/

	p = &G;

	if (CreateGraph(p)) OutputMG(G);
	A = &AL;
	if (CreateALGraph(p, A)) OutputAL(AL);

	printf("\n深度遍历为：");
	DFSTraverse(AL, PrintChar);
	printf("\n广度遍历为：");
	BFSTraverse(AL, PrintChar);
	getchar();

}
