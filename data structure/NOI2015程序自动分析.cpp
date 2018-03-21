

//地址:https://www.luogu.org/problemnew/show/P1955
//题意:判断给你的条件式是否有矛盾
//题解:并查集+离散化

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define pii pair<int,int>


const int N=1e6+7;

int fa[N],num[N<<1],tmp[N<<1],cnt;
int fi(int x)
{
    if(x==fa[x])return x;
    return fa[x]=fi(fa[x]);
}
void merge(int u,int v)
{
    fa[fi(u)]=fi(v);
}
void discrete(int arr[],int n)
{
    for(int i=1;i<=n;i++)tmp[i]=arr[i];
    sort(tmp+1,tmp+1+n);
    cnt=unique(tmp+1,tmp+1+n)-(tmp+1);
}
int qry(int x)
{
    return lower_bound(tmp+1,tmp+1+cnt,x)-tmp;
}
int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        queue<pii>p,q;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=N;i++)fa[i]=i;
        int i;
        int u,v,w;
        int o=0;
        for(i=0;i<n;i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (u > v)swap(u, v);
            num[o++]=u;
            num[o++]=v;
            if(w)p.push(pii(u,v));
            else q.push(pii(u,v));
        }
        discrete(num,o);
        while(p.size())
        {
            pii now=p.front();p.pop();
            merge(qry(now.first),qry(now.second));
        }
        while(q.size())
        {
            pii now=q.front();
            if(fi(qry(now.first))==fi(qry(now.second)))break;
            q.pop();
        }
        if(q.empty())printf("YES\n");
        else printf("NO\n");
    }
}


