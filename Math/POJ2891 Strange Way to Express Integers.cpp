

//地址:http://poj.org/problem?id=2891
//题解:中国剩余定理模板题
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



ll m[50005],r[50005];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b) { x=1;y=0;return a; }
    ll d=exgcd(b,a%b,y,x);y-=x*(a/b);return d;
}
ll china(int n)  //m[i]模数,r[i]余数,n个数
{
    ll a,b,c,c1,c2,x,y,d;
    a=m[0];c1=r[0];
    if(c1==0)c1=m[0];
    for(int i=1;i<n;i++)
    {
        b=m[i];c2=r[i];
        d=exgcd(a,b,x,y);
        c=c2-c1;
        if(c%d)return -1;
        ll b1=b/d;
        x=((c/d*x)%b1+b1)%b1;   //最小整数解
        c1=a*x+c1;	//新方程的c1
        a=a*b1;		//新方程的a
    }
    return c1;
}


int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lld%lld",m+i,r+i);
        printf("%lld\n",china(n));
    }
}
