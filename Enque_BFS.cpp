#include"stdio.h"
#include"stdlib.h"
#define MAX_VERTEX_NUM 10      /*定义最大顶点数*/
typedef int Vertex;
typedef struct  ArcNode{       /*表结点*/
    int adjvex;               /*邻接点域*/
    struct  ArcNode *nextarc; /*指向下一个表结点*/
}ArcNode;
typedef struct VNode{           /*头结点*/
    Vertex data;                  /*顶点域*/
    ArcNode *firstarc;          /*指向第一个表结点*/
}VNode,AdjList[MAX_VERTEX_NUM]; /*AdjList是数组类型*/
typedef struct { 
    AdjList vertices;           /*邻接表中数组定义*/
    int vexnum,arcnum;          /*图中当前顶点数和边数*/
} ALGraph;                 /*图类型*/
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MAX_VERTEX_NUM];/*定义标志向量，为全局变量*/
typedef struct 
{
    int front;
    int rear;
    int Queue[10];
}queue;
void Enqueue(queue &Q,int v);
void Dequeue(queue &Q,int *v);
void Initqueue(queue &Q);
int Empty(queue Q);
//!重点从此开始
void BFS(ALGraph *G,int v)
{
    ArcNode *p;
    queue Q;
    int index;
    visited[v]=TRUE;
    Initqueue(Q);
    while(Empty(Q))
    {
        Dequeue(Q,&index);
        p=G->vertices[index].firstarc;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                visited[p->adjvex]=TRUE;
                Enqueue(Q,p->adjvex);
            }
            p=p->nextarc;
        }
    }
}