

//地址:http://poj.org/problem?id=2054
//题意:给定一棵数,对该树进行染色,只有当父亲染完之后,儿子才能染色,第k次染色值: k*val[i]  ,求染完所有结点的染色值最小
//题解:贪心,找出当前最大结点,该结点必在其父亲结点染完色之后染色,于是可以把该结点跟其父亲结点合并成一个结点,然后根据该法则,把所有结点最终都
//     弄成一个集合,然后乘以其价值即为最终答案

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
#define ull unsigned long long
#define PI acos(-1.0)
#define E 2.7182818284590452353602874713527
#define bg(x) cout<<x<<"@@@"<<endl
#define lowbit(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
#define pii pair<int,int>
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


int val[1200],fa[1200],vis[1200],t[1200];
int n,r;

int fi()
{
    int pos=0;
    double mx=-1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&i!=r&&val[i]*1.0/t[i]>mx)
        {
            mx=val[i]*1.0/t[i];
            pos=i;
        }
    }
    return pos;
}
void uni(int pra,int son)
{
    val[pra]+=val[son];
    t[pra]+=t[son];
}
ll work()
{
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        int now=fi();
        vis[now]=1;
        int pra=fa[now];
        while(vis[pra])pra=fa[pra];
        ans+=t[pra]*val[now];
        uni(pra,now);
    }
    ans+=val[r];
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&r))
    {
        if(n==0&&r==0)break;
        memset(vis,0, sizeof(vis));
        memset(fa,0,sizeof(fa));
        for(int i=1;i<=n;i++)rd(val[i]),t[i]=1;
        int x,y;
        for(int i=1;i<n;i++)
        {
            rd(x);rd(y);
            fa[y]=x;
        }
        we(work());
    }
}
