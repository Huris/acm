

#include <bits/stdc++.h>
using namespace std;

#define VertexType int //顶点元素类型
#define MAX_VERTEX_NUM 500  //顶点最大个数
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int weight; //边的权
}ArcNode;  //表结点
typedef struct VNode
{
    int degree,indegree;//顶点的度，入度
    VertexType data;
    ArcNode *firstarc;
    VNode(){degree=0;indegree=0;data=0;firstarc=NULL;}
}VNode/*头结点*/,AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;//顶点的实际数，边的实际数
}ALGraph;

ALGraph G;  //图,用邻接表存储
int top[MAX_VERTEX_NUM];  //用于存放拓扑排序

void input()    //输入图
{
    printf("请输入顶点数:");scanf("%d",&G.vexnum);
    printf("请输入边数:");scanf("%d",&G.arcnum);
    printf("请输入各条边的情况:\n");
    int u,v,w;
    for(int i=0;i<G.arcnum;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        ArcNode *tmp=(ArcNode*)malloc(sizeof(ArcNode));
        tmp->weight=w;
        tmp->adjvex=v;
        tmp->nextarc=G.vertices[u].firstarc;
        G.vertices[u].firstarc=tmp;
        G.vertices[u].degree++;
        G.vertices[v].indegree++;
        G.vertices[v].degree++;
    }
}
void output()   //邻接表形式输出图
{
    for(int i=1;i<=G.vexnum;i++)
    {
        printf("%d",i);
        ArcNode *nw=G.vertices[i].firstarc;
        while(nw!=NULL)
        {
            printf("-->%d",nw->adjvex);
            nw=nw->nextarc;
        }
        printf("-->NULL\n");
    }
}
void cal_degree()  //输出各顶点的度数
{
    for(int i=1;i<=G.vexnum;i++)
    {
        printf("vex:%d degree:%d\n",i,G.vertices[i].degree);
    }
}

void topological_sort()
{
    queue<int>que;
    int num=0;
    for(int i=1;i<=G.vexnum;i++)
    {
        if(G.vertices[i].indegree==0)
        {
            que.push(i);
            top[num++]=i;
        }
    }
    while(!que.empty())
    {
        int nw=que.front();que.pop();
        ArcNode *now=G.vertices[nw].firstarc;
        while(now!=NULL)
        {
            G.vertices[now->adjvex].indegree--;
            if(G.vertices[now->adjvex].indegree==0)
            {
                que.push(now->adjvex);
                top[num++]=now->adjvex;
            }
            now=now->nextarc;
        }
    }
    if(num!=G.vexnum)printf("该图为有环图,无拓扑排序\n");
    else
    {
        printf("该图的拓扑排序为:\n");
        for(int i=0;i<num;i++)
        {
            printf("%d ",top[i]);
        }
        printf("\n");
    }
}
int main()
{
    input();
    output();
    cal_degree();
    topological_sort();
}
