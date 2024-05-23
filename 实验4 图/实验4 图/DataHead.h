#pragma once
#include<stdio.h>
#include <corecrt_malloc.h>
#include<Stdbool.h>
/*该头文件包含数据结构预定义的常量以及类型*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //不可行
#define OVERFLOW -2   //溢出

//Status 是函数的类型，它的值是函数结果状态代码
typedef int Status;

typedef int VRType;   //VRType是顶点关系类型，对于无权图，用0和1来表示是否相邻，对于带权图，则为权值类型
typedef int InfoType;//该弧相关信息的指针
typedef char VertexType; //顶点向量


//队列部分数据类型定义

/*队列内的元素类型为整数类型*/
typedef int QElemType;

typedef struct QNode      //结点数据类型
{
    QElemType        data;     //数据域为整形元素
    struct QNode* next;
} QNode, * QueuePtr;

typedef struct
{
    QueuePtr    front;			   //队首指针
    QueuePtr    rear;			  //队尾指针
}LinkQueue;

//----------图的数组（邻接矩阵）存储表示
#define INT_MAX   10000                            //无穷大定义为10000
#define  INFINITY         INT_MAX                //最大值无穷大
#define  MAX_VERTEX_NUM       20         //最大顶点个数


typedef enum {
    DG, DN, UDG, UDN
    //有向图、有向网、无向图、无向网
}Graphkind;

/*单词
1.顶点：             vertex
2.信息：             info
3. 邻接矩阵：    adjacency matrix
4.弧:                   arc
*/


typedef struct ArcCell {
    VRType adj;		//VRType是顶点关系类型，对于无权图，用0和1来表示是否相邻，对于带权图，则为权值类型

    InfoType* info;      //该弧相关信息的指针

}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


typedef struct {
    VertexType  vexs[MAX_VERTEX_NUM];             //顶点向量(字符型)
    AdjMatrix  arcs;													 //邻接矩阵（Adjacency matrix）
    int       vexnum, arcnum;										//图的当前的顶点数和弧数
    Graphkind kind;													//图的种类标志 有向图、有向网、无向图、无向网
}MGraph;


//邻接表的数据类型定义
typedef struct ArcNode {
    int       adjvex;                        //该弧所指向的顶点的位置
    struct ArcNode* nextarc;       //指向下一条弧的指针
    InfoType* info;                      //该弧相关信息的指针
}ArcNode;


typedef struct VNode {
    VertexType data;                 //顶点信息（char类型）
    ArcNode* firstarc;              //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];



typedef struct {
    AdjList vertices;
    int     vexnum, arcnum;     //图当前的顶点数和弧数
    int     kind;                        //图的种类标志
  
}ALGraph;

bool visited[MAX_VERTEX_NUM];      //定义访问标志数组，存储bool类型
Status(*VisitFunc)(char v);


/*函数声明*/
Status CreateGraph(MGraph* G);                                        //选择构造什么类型的图G
Status CreateDG(MGraph* G);                                            //构造有向图
Status CreateDN(MGraph* G);                                           //构造无向网
Status CreateUDG(MGraph* G);                                       //构造无向网
Status CreateUDN(MGraph* G);                                      //构造无向网
Status CreateALGraph(MGraph* M, ALGraph* AL);       /*创建邻接表，数据来源于已知的邻接矩阵*/
void OutputMG(MGraph G);                                           //输出邻接矩阵
void OutputAL(ALGraph AL);                                         //输出邻接表
int LocateVex(MGraph G, VertexType v);                     //确定带有权值的边在矩阵中的存储位置
Status PrintInt(int e);                                                    /*Visit 函数*/
Status PrintChar(char vex);                                          /*Visit 函数*/
void DFSTraverse(ALGraph G, Status(*Visit)(char v));/*  算法7.4   对图G作深度优先遍历。*/
void DFS(ALGraph G, int v);                         /*  算法7.5     从第v个顶点出发递归地深度优先遍历图G。*/
void BFSTraverse(ALGraph G, Status(*Visit)(char v));/*   按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。*/
Status InitQueue(LinkQueue* Q);                           //初始化队列
Status EnQueue(LinkQueue* Q, int e);                  //入队
Status DeQueue(LinkQueue* Q, int* e);               //出队
Status QueueEmpty(LinkQueue Q);                   //队满判定



Status CreateGraph(MGraph* G) {            // 的代码，但是实习中不用枚举类型，而是用int类型来代替，代码在下方
    //采用数组(邻接矩阵)表示法，构造图G
    printf("请选择创建图的类型 0：有向图DG\t1：有向网DN\t2：无向图UDG\t3：无向网UDN\n");
    scanf_s("%d", &(G->kind));
    switch (G->kind) {
    case DG:return CreateDG(G);
    case DN:return CreateDN(G);
    case UDG:return CreateUDG(G);
    case UDN:return CreateUDN(G);
    default: return ERROR;
    }

}


//创建有向图
Status CreateDG(MGraph* G) {/*   改造自算法 7.2 */
  /*  采用数组（邻接矩阵）表示法，构造有向图 */
      // 采用数组（邻接矩阵）表示法，构造无向网G。
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** 加上此句getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // 构造顶点向量
    for (i = 0; i < G->vexnum; ++i)  // 初始化邻接矩阵
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // 构造邻接矩阵
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        // 输入一条边依附的顶点及权值
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // 确定v1和v2在G中位置
        G->arcs[i][j].adj = 1;                // 弧<v1,v2>的权值
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // 输入弧含有相关信息
    }
    return OK;
} /*  CreateDG */




//创建有向网
Status CreateDN(MGraph* G) {
    // 采用数组（邻接矩阵）表示法，构造无向网G。
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** 加上此句getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // 构造顶点向量
    for (i = 0; i < G->vexnum; ++i)  // 初始化邻接矩阵
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // 构造邻接矩阵
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        printf("w (int) : ");   scanf_s("%d", &w); getchar();
        // 输入一条边依附的顶点及权值
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // 确定v1和v2在G中位置
        G->arcs[i][j].adj = w;                // 弧<v1,v2>的权值
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // 输入弧含有相关信息
    }
    return OK;
}





//创建无向图
Status CreateUDG(MGraph* G) {/*   改造自算法 7.2 */
  /*  采用数组（邻接矩阵）表示法，构造无向图 */
    int i, j, k, w;
    VertexType  v1, v2;
    printf("请输入顶点个数G->vexnum :");  scanf_s("%d", &G->vexnum);
    printf("请输入弧的条数G->arcnum :");   scanf_s("%d", &G->arcnum);
    getchar();  /*** 加上此句getchar()!!! ***/
    /*  scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);       */
    for (i = 0; i < G->vexnum; i++) {
        printf("请输入顶点G->vexs[%d]的名称(字符型):", i);
        scanf_s("%c", &G->vexs[i]);
        getchar();
    } /*  构造顶点向量 */
    for (i = 0; i < G->vexnum; ++i)  /*  初始化邻接矩阵 ，全部赋值为0*/
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = 0; /* {adj,info} */
            G->arcs[i][j].info = NULL;

        }
    for (k = 0; k < G->arcnum; ++k) {  /*  构造邻接矩阵
      printf("v1 (char) : ");  scanf("%c", &v1);getchar();
      printf("v2 (char) : ");  scanf("%c", &v2);getchar();
      printf("w (int) : " );   scanf("%d", &w); getchar();    */
        printf("请依次输入弧尾、弧头顶点名称\n");
        //scanf_s("%c %c", &v1, &v2);
        scanf_s(" %c", &v1);
        scanf_s(" %c", &v2);
        /*  输入一条边依附的顶点 */
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        /*  确定v1和v2在G中位置 */
        G->arcs[i][j].adj = 1;                /*  弧<v1,v2>的权值为1，表示两点相邻接 */
        /*  if (IncInfo) scanf(G.arcs[i][j].info); /*  输入弧含有相关信息 */
        G->arcs[j][i].adj = G->arcs[i][j].adj; /*  置<v1,v2>的对称弧<v2,v1> */
    }
    G->kind = UDG;
    return OK;
} /*  CreateUDG */


//创建无向网
Status CreateUDN(MGraph* G) {//  算法 7.2
    // 采用数组（邻接矩阵）表示法，构造无向网G。
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** 加上此句getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // 构造顶点向量
    for (i = 0; i < G->vexnum; ++i)  // 初始化邻接矩阵
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // 构造邻接矩阵
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        printf("w (int) : ");   scanf_s("%d", &w); getchar();
        // 输入一条边依附的顶点及权值
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // 确定v1和v2在G中位置
        G->arcs[i][j].adj = w;                // 弧<v1,v2>的权值
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // 输入弧含有相关信息
        G->arcs[j][i].adj = G->arcs[i][j].adj; // 置<v1,v2>的对称弧<v2,v1>
    }
    return OK;
} // CreateUDN




int LocateVex(MGraph G, VertexType v)
{

    for (int i = 0; i < G.vexnum; i++)
    {
        if (v == G.vexs[i])      //如果字符a与图中的字符相同
            return i;                //返回该字符在一维数组中的位置
    }

}







/*创建邻接表，数据来源于已知的邻接矩阵*/
Status CreateALGraph(MGraph* M, ALGraph* AL) {
    int i, j;
    ArcNode* head, * p;
    AL->vexnum = M->vexnum;
    AL->arcnum = M->arcnum;
    AL->kind = M->kind;
    for (i = 0; i < M->vexnum; i++) AL->vertices[i].data = M->vexs[i];
    head = (ArcNode*)malloc(sizeof(ArcNode)); /*单链表 头指针*/
    for (i = 0; i < M->vexnum; i++)
    {
        head->nextarc = NULL;
        for (j = 0; j < M->vexnum; j++)
        {
            if ((M->arcs[i][j].adj != INFINITY) && (M->arcs[i][j].adj != 0))
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                //p->info = M->arcs[i][j].info;
                p->nextarc = head->nextarc;
                p->adjvex = j;/*j顶点*/
                head->nextarc = p;   /*逆序插入各弧*/
            }
        }
        AL->vertices[i].firstarc = head->nextarc;
    }
    free(head);
    return(1);
}




/*输出邻接矩阵*/
void OutputMG(MGraph G)
{
    int i, j;
    printf("\n邻接矩阵为:");
    for (i = 0; i < G.vexnum; i++)
    {
        printf("\n");
        for (j = 0; j < G.vexnum; j++)
        {
            printf("%d\t", G.arcs[i][j].adj);
        }
    }
}

//输出邻接表
void OutputAL(ALGraph AL) {
    int i, j;
    ArcNode* p;
    printf("\n邻接表为：");
    for (i = 0; i < AL.vexnum; i++)
    {
        printf("\n顶点%c->", AL.vertices[i].data);
        p = AL.vertices[i].firstarc;
        while (p)     /*输出单链表*/
        {
            printf("%d\t", p->adjvex);
            p = p->nextarc;
        }
    }
}



Status PrintInt(int e) {   /*Visit 函数*/
    printf("  %d", e);           /*输出值，以强调visit函数*/
    return OK;
}

Status PrintChar(char vex)
{
    printf("  %c", vex);           /*输出值，以强调visit函数*/
    return OK;
}



void DFSTraverse(ALGraph G, Status(*Visit)(char v)) {  /*  算法7.4 */
 /*  对图G作深度优先遍历。     对尚未访问的顶点调用DFS */
    int v;
    VisitFunc = Visit; // 使用全局变量VisitFunc，使DFS不必设函数指针参数
    for (v = 0; v < G.vexnum; ++v) visited[v] = false; // 访问标志数组初始化
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v]) DFS(G, v);         // 对尚未访问的顶点调用DFS

}

void DFS(ALGraph G, int v) {  /*  算法7.5 */
 /*  算法7.5 */
   // 从第v个顶点出发递归地深度优先遍历图G。
    int w;
    visited[v] = true;   VisitFunc(G.vertices[v].data);  // 访问第v个顶点的名称
    for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w))
        if (!visited[w])   // 对v的尚未访问的邻接顶点w递归调用DFS
            DFS(G, w);
}


void BFSTraverse(ALGraph G, Status(*Visit)(char v))
{/*   算法7.6 */
 // 按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。
    int v, w;  //结点的data值，为整数
    LinkQueue Q;
    LinkQueue* p = &Q;
    int u = 0; //整数，需先初始化
    for (v = 0; v < G.vexnum; ++v) visited[v] = FALSE;
    InitQueue(p);                     // 置空的辅助队列Q
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v]) {              // v尚未访问
            visited[v] = TRUE;  Visit(G.vertices[v].data); // 访问v
            EnQueue(p, v);                // v入队列
            while (!QueueEmpty(Q)) {
                DeQueue(p, &u);              // 队头元素出队并置为u
                for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
                    if (!visited[w]) {        // u的尚未访问的邻接顶点w入队列Q
                        visited[w] = TRUE;  Visit(G.vertices[w].data);
                        EnQueue(p, w);
                    }//if   
            }//while                       
        }//if
} /*  BFSTraverse */


int FirstAdjVex(ALGraph G, int v) {
    ArcNode* p;
    p = G.vertices[v].firstarc;
    if (p != NULL) return p->adjvex;
    else  return -1;/*p为空*/
}

int NextAdjVex(ALGraph G, int v, int w) {
    ArcNode* p;
    p = G.vertices[v].firstarc;
    while (p) {
        if ((p->adjvex == w) && (p->nextarc != NULL)) return p->nextarc->adjvex;
        p = p->nextarc;
    }
    return -1;
}

Status InitQueue(LinkQueue* Q){     
    //构造空的单链队列源代码 课本P62
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*Q).front) exit(OVERFLOW);  //存储分配失败
    (*Q).front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue* Q, int e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e; p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue* Q, int* e)
{
    QueuePtr p;
    if (Q->front == Q->rear) return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    if (Q.rear == Q.front) return TRUE;
    else return FALSE;
}
