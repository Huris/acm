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
ll mod;
struct node
{
    int l,r;
    ll v,add,mul;   //标记
}tre[N<<2];
ll bd(int x,int l,int r)
{
    tre[x]=node{l,r,0,0,1}; //初始化
    if(l==r){scanf("%lld",&tre[x].v);return tre[x].v%=mod;}
    int m=tre[x].l+tre[x].r>>1;
    return tre[x].v=(bd(ls(x),l,m)+bd(rs(x),m+1,r))%mod;
}
void dn(int x)
{
    tre[ls(x)].add=(tre[x].add+tre[ls(x)].add*tre[x].mul)%mod;
    tre[rs(x)].add=(tre[x].add+tre[rs(x)].add*tre[x].mul)%mod;
    tre[ls(x)].mul=(tre[x].mul*tre[ls(x)].mul)%mod;
    tre[rs(x)].mul=(tre[x].mul*tre[rs(x)].mul)%mod;
    tre[ls(x)].v=(tre[ls(x)].v*tre[x].mul+tre[x].add*(tre[ls(x)].r-tre[ls(x)].l+1))%mod;
    tre[rs(x)].v=(tre[rs(x)].v*tre[x].mul+tre[x].add*(tre[rs(x)].r-tre[rs(x)].l+1))%mod;
    tre[x].add=0;
    tre[x].mul=1;
}
ll qry(int x,int l,int r)
{
    dn(x);
    if(l<=tre[x].l&&r>=tre[x].r)return tre[x].v%mod;
    ll ans=0;
    int m=tre[x].l+tre[x].r>>1;
    if(l<=m)ans=(ans+qry(ls(x),l,r))%mod;
    if(r>m)ans=(ans+qry(rs(x),l,r))%mod;
    return ans%mod;
}
void ud(int x,int l,int r,int k,ll v)
{
    dn(x);
    if(k==1&&l<=tre[x].l&&r>=tre[x].r)  //区间乘
    {
        tre[x].mul=tre[x].mul*v%mod;
        tre[x].add=tre[x].add*v%mod;
        tre[x].v=tre[x].v*tre[x].mul%mod;
        return;
    }
    if(k==2&&l<=tre[x].l&&r>=tre[x].r) //区间加
    {
        tre[x].add=(tre[x].add+v)%mod;
        tre[x].v=(tre[x].v+tre[x].add*(tre[x].r-tre[x].l+1))%mod;
        return;
    }
    int m=tre[x].l+tre[x].r>>1;
    if(l<=m)ud(ls(x),l,r,k,v);
    if(r>m)ud(rs(x),l,r,k,v);
    tre[x].v=(tre[ls(x)].v+tre[rs(x)].v)%mod;
}
int main()
{
    int n,m;
    scanf("%d%d%lld",&n,&m,&mod);
    bd(1,1,n);
    int a,b,c;
    ll d;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==3)
        {
            printf("%lld\n",qry(1,b,c));
        }
        else
        {
            scanf("%lld",&d);
            ud(1,b,c,a,d);
        }
    }
}
