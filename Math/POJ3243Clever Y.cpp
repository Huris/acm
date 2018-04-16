

//地址:http://poj.org/problem?id=3243
//题意:求a^x=b(mod p)中x的最小值,其中a,b,p没有关系
//题解:大步小步算法模板题
//代码:
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
using namespace std;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long


const int N=50000;
const int H=999979;
int a,b,p,D;
int tot,head[H],nex[N],val[N],deg[N];
int n,cnt,pw[N];
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
void exgcd(int a,int b,int &x,int &y)
{
    b?(exgcd(b,a%b,y,x),y-=a/b*x):(x=1,y=0);
}
int inv(int a,int b)
{
    int x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
void ins(int d,int x)
{
    int u=x%H;
    for(int v=head[u];v;v=nex[v])
        if(val[v]==x&&deg[v]<d)
        {
            deg[v]=d;
            return;
        }
    nex[++tot]=head[u],head[u]=tot,val[tot]=x,deg[tot]=d;
}
int fi(int x)
{
    int u=x%H;
    for(int v=head[u];v;v=nex[v])
        if(val[v]==x)return deg[v];
    return -1;
}
int bsgs()
{
    memset(head,0,sizeof(head));
    cnt=tot=0,pw[0]=D=1;
    int r,y,P=1;
    while((r=gcd(a,p))!=1)
    {
        if(b%r!=0)return -1;
        ++cnt,b/=r,p/=r;
        D=(ll)D*(a/r)%p;
    }
    b=(ll)b*inv(D,p)%p;
    for(n=1;n*n<p;n++);
    for(int i=1;i<=n;i++)
        pw[i]=(ll)pw[i-1]*a%p;
    for(int i=0;i<n;i++)
        ins(i,(ll)pw[i]*b%p);
    for(int i=1;i<=n;i++)
    {
        P=(ll)P*pw[n]%p;
        if((y=fi(P))!=-1)
            return i*n-y+cnt;
    }
    return -1;
}
bool check()
{
    for(int i=0,t=1;i<=10;i++)
    {
        if(t%p==b)
        {
            printf("%d\n",i);
            return true;
        }
        t=(ll)t*a%p;
    }
    if(a==0)
    {
        puts("No Solution");
        return true;
    }
    return false;
}
int main()
{
    while(scanf("%d%d%d",&a,&p,&b)&&(ll)a+b+p>0)
    {
        a%=p,b%=p;
        if(check())continue;
        int ans=bsgs();
        if(ans==-1)puts("No Solution");
        else printf("%d\n",ans);
    }
}
