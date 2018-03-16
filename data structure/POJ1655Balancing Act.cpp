

//地址:http://poj.org/problem?id=1655
//题意:求树的重心和删去重心后最大子树的结点数
//题解:树重心模板题

//代码:
#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <stack>
#include <stdlib.h>
#include <ctype.h>
#include <queue>
#include <bitset>
#include<cassert>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define bg(x) cout<<x<<"@@@"<<endl
template <typename T>inline void rd(T &x) {
    char c=getchar();int s=1;
    while(c!='-'&&!isdigit(c))c=getchar();
    if(c=='-')s=-1,x=0;else x=c-'0';
    while(c=getchar(),isdigit(c))x=x*10+c-'0';x*=s;
}
template <typename T>inline void wd(T x){
    if(x/10)wd(x/10);putchar(x%10+'0');
}
template <typename T>inline void we(T x){
    if(x<0)x=-x,putchar('-');wd(x);putchar('\n');
}


const int N=1e6+7;
int n;      //n个结点
int tot,head[N]; //若边集tot从0开始计数,则head初始为-1
int to[N],nex[N];
int vis[N];
int son[N];    //以结点1为根结点,各结点的孩子数
int pos,ans;   //pos重心,ans删去重心后最大子树结点数
void init()
{
    tot=0;
    ans=inf;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
void add(int u,int v)
{
    to[tot]=v;
    nex[tot]=head[u];
    head[u]=tot++;
}
void dfs(int x)
{
    vis[x]=1;
    son[x]=1;
    int mx=0;
    for(int i=head[x];~i;i=nex[i])
    {
        int y=to[i];
        if(vis[y])continue;
        dfs(y);
        son[x]+=son[y];
        mx=max(mx,son[y]);
    }
    mx=max(mx,n-son[x]);
    if(mx<ans||(mx==ans&&x<pos))
    {
        pos=x;
        ans=mx;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        rd(n);
        init();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        dfs(1);
        printf("%d %d\n",pos,ans);
    }
}
