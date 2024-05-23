#pragma once
#include<stdio.h>
#include <corecrt_malloc.h>
#include<Stdbool.h>
/*��ͷ�ļ��������ݽṹԤ����ĳ����Լ�����*/
#define TRUE  1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1  //������
#define OVERFLOW -2   //���

//Status �Ǻ��������ͣ�����ֵ�Ǻ������״̬����
typedef int Status;

typedef int VRType;   //VRType�Ƕ����ϵ���ͣ�������Ȩͼ����0��1����ʾ�Ƿ����ڣ����ڴ�Ȩͼ����ΪȨֵ����
typedef int InfoType;//�û������Ϣ��ָ��
typedef char VertexType; //��������


//���в����������Ͷ���

/*�����ڵ�Ԫ������Ϊ��������*/
typedef int QElemType;

typedef struct QNode      //�����������
{
    QElemType        data;     //������Ϊ����Ԫ��
    struct QNode* next;
} QNode, * QueuePtr;

typedef struct
{
    QueuePtr    front;			   //����ָ��
    QueuePtr    rear;			  //��βָ��
}LinkQueue;

//----------ͼ�����飨�ڽӾ��󣩴洢��ʾ
#define INT_MAX   10000                            //�������Ϊ10000
#define  INFINITY         INT_MAX                //���ֵ�����
#define  MAX_VERTEX_NUM       20         //��󶥵����


typedef enum {
    DG, DN, UDG, UDN
    //����ͼ��������������ͼ��������
}Graphkind;

/*����
1.���㣺             vertex
2.��Ϣ��             info
3. �ڽӾ���    adjacency matrix
4.��:                   arc
*/


typedef struct ArcCell {
    VRType adj;		//VRType�Ƕ����ϵ���ͣ�������Ȩͼ����0��1����ʾ�Ƿ����ڣ����ڴ�Ȩͼ����ΪȨֵ����

    InfoType* info;      //�û������Ϣ��ָ��

}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


typedef struct {
    VertexType  vexs[MAX_VERTEX_NUM];             //��������(�ַ���)
    AdjMatrix  arcs;													 //�ڽӾ���Adjacency matrix��
    int       vexnum, arcnum;										//ͼ�ĵ�ǰ�Ķ������ͻ���
    Graphkind kind;													//ͼ�������־ ����ͼ��������������ͼ��������
}MGraph;


//�ڽӱ���������Ͷ���
typedef struct ArcNode {
    int       adjvex;                        //�û���ָ��Ķ����λ��
    struct ArcNode* nextarc;       //ָ����һ������ָ��
    InfoType* info;                      //�û������Ϣ��ָ��
}ArcNode;


typedef struct VNode {
    VertexType data;                 //������Ϣ��char���ͣ�
    ArcNode* firstarc;              //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];



typedef struct {
    AdjList vertices;
    int     vexnum, arcnum;     //ͼ��ǰ�Ķ������ͻ���
    int     kind;                        //ͼ�������־
  
}ALGraph;

bool visited[MAX_VERTEX_NUM];      //������ʱ�־���飬�洢bool����
Status(*VisitFunc)(char v);


/*��������*/
Status CreateGraph(MGraph* G);                                        //ѡ����ʲô���͵�ͼG
Status CreateDG(MGraph* G);                                            //��������ͼ
Status CreateDN(MGraph* G);                                           //����������
Status CreateUDG(MGraph* G);                                       //����������
Status CreateUDN(MGraph* G);                                      //����������
Status CreateALGraph(MGraph* M, ALGraph* AL);       /*�����ڽӱ�������Դ����֪���ڽӾ���*/
void OutputMG(MGraph G);                                           //����ڽӾ���
void OutputAL(ALGraph AL);                                         //����ڽӱ�
int LocateVex(MGraph G, VertexType v);                     //ȷ������Ȩֵ�ı��ھ����еĴ洢λ��
Status PrintInt(int e);                                                    /*Visit ����*/
Status PrintChar(char vex);                                          /*Visit ����*/
void DFSTraverse(ALGraph G, Status(*Visit)(char v));/*  �㷨7.4   ��ͼG��������ȱ�����*/
void DFS(ALGraph G, int v);                         /*  �㷨7.5     �ӵ�v����������ݹ��������ȱ���ͼG��*/
void BFSTraverse(ALGraph G, Status(*Visit)(char v));/*   ��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited��*/
Status InitQueue(LinkQueue* Q);                           //��ʼ������
Status EnQueue(LinkQueue* Q, int e);                  //���
Status DeQueue(LinkQueue* Q, int* e);               //����
Status QueueEmpty(LinkQueue Q);                   //�����ж�



Status CreateGraph(MGraph* G) {            // �Ĵ��룬����ʵϰ�в���ö�����ͣ�������int���������棬�������·�
    //��������(�ڽӾ���)��ʾ��������ͼG
    printf("��ѡ�񴴽�ͼ������ 0������ͼDG\t1��������DN\t2������ͼUDG\t3��������UDN\n");
    scanf_s("%d", &(G->kind));
    switch (G->kind) {
    case DG:return CreateDG(G);
    case DN:return CreateDN(G);
    case UDG:return CreateUDG(G);
    case UDN:return CreateUDN(G);
    default: return ERROR;
    }

}


//��������ͼ
Status CreateDG(MGraph* G) {/*   �������㷨 7.2 */
  /*  �������飨�ڽӾ��󣩱�ʾ������������ͼ */
      // �������飨�ڽӾ��󣩱�ʾ��������������G��
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** ���ϴ˾�getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // ���춥������
    for (i = 0; i < G->vexnum; ++i)  // ��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // �����ڽӾ���
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        // ����һ���������Ķ��㼰Ȩֵ
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // ȷ��v1��v2��G��λ��
        G->arcs[i][j].adj = 1;                // ��<v1,v2>��Ȩֵ
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // ���뻡���������Ϣ
    }
    return OK;
} /*  CreateDG */




//����������
Status CreateDN(MGraph* G) {
    // �������飨�ڽӾ��󣩱�ʾ��������������G��
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** ���ϴ˾�getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // ���춥������
    for (i = 0; i < G->vexnum; ++i)  // ��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // �����ڽӾ���
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        printf("w (int) : ");   scanf_s("%d", &w); getchar();
        // ����һ���������Ķ��㼰Ȩֵ
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // ȷ��v1��v2��G��λ��
        G->arcs[i][j].adj = w;                // ��<v1,v2>��Ȩֵ
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // ���뻡���������Ϣ
    }
    return OK;
}





//��������ͼ
Status CreateUDG(MGraph* G) {/*   �������㷨 7.2 */
  /*  �������飨�ڽӾ��󣩱�ʾ������������ͼ */
    int i, j, k, w;
    VertexType  v1, v2;
    printf("�����붥�����G->vexnum :");  scanf_s("%d", &G->vexnum);
    printf("�����뻡������G->arcnum :");   scanf_s("%d", &G->arcnum);
    getchar();  /*** ���ϴ˾�getchar()!!! ***/
    /*  scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);       */
    for (i = 0; i < G->vexnum; i++) {
        printf("�����붥��G->vexs[%d]������(�ַ���):", i);
        scanf_s("%c", &G->vexs[i]);
        getchar();
    } /*  ���춥������ */
    for (i = 0; i < G->vexnum; ++i)  /*  ��ʼ���ڽӾ��� ��ȫ����ֵΪ0*/
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = 0; /* {adj,info} */
            G->arcs[i][j].info = NULL;

        }
    for (k = 0; k < G->arcnum; ++k) {  /*  �����ڽӾ���
      printf("v1 (char) : ");  scanf("%c", &v1);getchar();
      printf("v2 (char) : ");  scanf("%c", &v2);getchar();
      printf("w (int) : " );   scanf("%d", &w); getchar();    */
        printf("���������뻡β����ͷ��������\n");
        //scanf_s("%c %c", &v1, &v2);
        scanf_s(" %c", &v1);
        scanf_s(" %c", &v2);
        /*  ����һ���������Ķ��� */
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        /*  ȷ��v1��v2��G��λ�� */
        G->arcs[i][j].adj = 1;                /*  ��<v1,v2>��ȨֵΪ1����ʾ�������ڽ� */
        /*  if (IncInfo) scanf(G.arcs[i][j].info); /*  ���뻡���������Ϣ */
        G->arcs[j][i].adj = G->arcs[i][j].adj; /*  ��<v1,v2>�ĶԳƻ�<v2,v1> */
    }
    G->kind = UDG;
    return OK;
} /*  CreateUDG */


//����������
Status CreateUDN(MGraph* G) {//  �㷨 7.2
    // �������飨�ڽӾ��󣩱�ʾ��������������G��
    int i, j, k, w;
    VertexType  v1, v2;
    printf("G.vexnum :");  scanf_s("%d", &(G->vexnum));
    printf("G.arcnum :");   scanf_s("%d", &(G->arcnum));
    getchar();  /*** ���ϴ˾�getchar()!!! ***/
    // scanf_s("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
    for (i = 0; i < G->vexnum; i++) {
        printf("G.vexs[%d] : ", i);
        scanf_s(" %c", &(G->vexs[i]));
        getchar();
    } // ���춥������
    for (i = 0; i < G->vexnum; ++i)  // ��ʼ���ڽӾ���
        for (j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j].adj = INFINITY; //{adj,info}
            G->arcs[i][j].info = NULL;
        }
    for (k = 0; k < G->arcnum; ++k) {  // �����ڽӾ���
        printf("v1 (char) : ");  scanf_s("%c", &v1); getchar();
        printf("v2 (char) : ");  scanf_s("%c", &v2); getchar();
        printf("w (int) : ");   scanf_s("%d", &w); getchar();
        // ����һ���������Ķ��㼰Ȩֵ
        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);
        // ȷ��v1��v2��G��λ��
        G->arcs[i][j].adj = w;                // ��<v1,v2>��Ȩֵ
        //if (IncInfo) scanf_s(G.arcs[i][j].info); // ���뻡���������Ϣ
        G->arcs[j][i].adj = G->arcs[i][j].adj; // ��<v1,v2>�ĶԳƻ�<v2,v1>
    }
    return OK;
} // CreateUDN




int LocateVex(MGraph G, VertexType v)
{

    for (int i = 0; i < G.vexnum; i++)
    {
        if (v == G.vexs[i])      //����ַ�a��ͼ�е��ַ���ͬ
            return i;                //���ظ��ַ���һά�����е�λ��
    }

}







/*�����ڽӱ�������Դ����֪���ڽӾ���*/
Status CreateALGraph(MGraph* M, ALGraph* AL) {
    int i, j;
    ArcNode* head, * p;
    AL->vexnum = M->vexnum;
    AL->arcnum = M->arcnum;
    AL->kind = M->kind;
    for (i = 0; i < M->vexnum; i++) AL->vertices[i].data = M->vexs[i];
    head = (ArcNode*)malloc(sizeof(ArcNode)); /*������ ͷָ��*/
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
                p->adjvex = j;/*j����*/
                head->nextarc = p;   /*����������*/
            }
        }
        AL->vertices[i].firstarc = head->nextarc;
    }
    free(head);
    return(1);
}




/*����ڽӾ���*/
void OutputMG(MGraph G)
{
    int i, j;
    printf("\n�ڽӾ���Ϊ:");
    for (i = 0; i < G.vexnum; i++)
    {
        printf("\n");
        for (j = 0; j < G.vexnum; j++)
        {
            printf("%d\t", G.arcs[i][j].adj);
        }
    }
}

//����ڽӱ�
void OutputAL(ALGraph AL) {
    int i, j;
    ArcNode* p;
    printf("\n�ڽӱ�Ϊ��");
    for (i = 0; i < AL.vexnum; i++)
    {
        printf("\n����%c->", AL.vertices[i].data);
        p = AL.vertices[i].firstarc;
        while (p)     /*���������*/
        {
            printf("%d\t", p->adjvex);
            p = p->nextarc;
        }
    }
}



Status PrintInt(int e) {   /*Visit ����*/
    printf("  %d", e);           /*���ֵ����ǿ��visit����*/
    return OK;
}

Status PrintChar(char vex)
{
    printf("  %c", vex);           /*���ֵ����ǿ��visit����*/
    return OK;
}



void DFSTraverse(ALGraph G, Status(*Visit)(char v)) {  /*  �㷨7.4 */
 /*  ��ͼG��������ȱ�����     ����δ���ʵĶ������DFS */
    int v;
    VisitFunc = Visit; // ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
    for (v = 0; v < G.vexnum; ++v) visited[v] = false; // ���ʱ�־�����ʼ��
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v]) DFS(G, v);         // ����δ���ʵĶ������DFS

}

void DFS(ALGraph G, int v) {  /*  �㷨7.5 */
 /*  �㷨7.5 */
   // �ӵ�v����������ݹ��������ȱ���ͼG��
    int w;
    visited[v] = true;   VisitFunc(G.vertices[v].data);  // ���ʵ�v�����������
    for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w))
        if (!visited[w])   // ��v����δ���ʵ��ڽӶ���w�ݹ����DFS
            DFS(G, w);
}


void BFSTraverse(ALGraph G, Status(*Visit)(char v))
{/*   �㷨7.6 */
 // ��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited��
    int v, w;  //����dataֵ��Ϊ����
    LinkQueue Q;
    LinkQueue* p = &Q;
    int u = 0; //���������ȳ�ʼ��
    for (v = 0; v < G.vexnum; ++v) visited[v] = FALSE;
    InitQueue(p);                     // �ÿյĸ�������Q
    for (v = 0; v < G.vexnum; ++v)
        if (!visited[v]) {              // v��δ����
            visited[v] = TRUE;  Visit(G.vertices[v].data); // ����v
            EnQueue(p, v);                // v�����
            while (!QueueEmpty(Q)) {
                DeQueue(p, &u);              // ��ͷԪ�س��Ӳ���Ϊu
                for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
                    if (!visited[w]) {        // u����δ���ʵ��ڽӶ���w�����Q
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
    else  return -1;/*pΪ��*/
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
    //����յĵ�������Դ���� �α�P62
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*Q).front) exit(OVERFLOW);  //�洢����ʧ��
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
