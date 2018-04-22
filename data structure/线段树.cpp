

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <stack>
using namespace std;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long


#define ls(x) (x)<<1
#define rs(x) (x)<<1|1
const int N=1e6+7;
ll tre[N<<2],tg[N<<2];
inline void pu(int x)
{
    tre[x]=tre[ls(x)]+tre[rs(x)];
}
void build(int x,int l,int r)
{
    tg[x]=0;
    if(l==r){scanf("%lld",tre+x);return;}
    int m=l+r>>1;
    build(ls(x),l,m);
    build(rs(x),m+1,r);
    pu(x);
}
inline void fg(int x,int l,int r,ll v)
{
    tg[x]+=v;tre[x]+=v*(r-l+1);
}
inline void pd(int x,int l,int r)
{
    int m=l+r>>1;
    fg(ls(x),l,m,tg[x]);
    fg(rs(x),m+1,r,tg[x]);
    tg[x]=0;
}
inline void ud(int cl,int cr,int l,int r,int x,ll v)
{
    //[cl,cr]修改的区间,[l,r]当前节点所储存的区间,x当前节点
    if(cl<=l&&cr>=r)
    {
        tg[x]+=v;
        tre[x]+=v*(r-l+1);
        return;
    }
    pd(x,l,r);
    int m=l+r>>1;
    if(cl<=m)ud(cl,cr,l,m,ls(x),v);
    if(cr>m)ud(cl,cr,m+1,r,rs(x),v);
    pu(x);
}
inline ll qry(int cl,int cr,int l,int r,int x)
{
    ll ans=0;
    if(cl<=l&&cr>=r)return tre[x];
    pd(x,l,r);
    int m=l+r>>1;
    if(cl<=m)ans+=qry(cl,cr,l,m,ls(x));
    if(cr>m)ans+=qry(cl,cr,m+1,r,rs(x));
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    int a,b,c;
    ll d;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            scanf("%lld",&d);
            ud(b,c,1,n,1,d);
        }
        else
        {
            printf("%lld\n",qry(b,c,1,n,1));
        }
    }
}
