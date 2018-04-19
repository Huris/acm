

//地址:https://begin.lydsy.com/JudgeOnline/problem.php?id=4833
//题意:二维坐标中给n个点,求三个点形成'v'和'^'的个数
//题解:树状数组

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


const int N=1e6+7;
int l[N],r[N];
int a[N];
int c[N];
int n;
void ins(int x,int v) {for(;x<=n;x+=x&-x)c[x]+=v;}
int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(c,0, sizeof(c));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            l[i]+=sum(a[i]-1);
            ins(a[i],1);
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--)
        {
            r[i]+=sum(a[i]-1);
            ins(a[i],1);
        }
        ll s1=0,s2=0;
        for(int i=1;i<=n;i++)s1+=l[i]*r[i];
        memset(c,0, sizeof(c));
        memset(l,0, sizeof(l));
        memset(r,0, sizeof(r));
        for(int i=1;i<=n;i++)
        {
            l[i]+=sum(n)-sum(a[i]);
            ins(a[i],1);
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--)
        {
            r[i]+=sum(n)-sum(a[i]);
            ins(a[i],1);
        }
        for(int i=1;i<=n;i++)s2+=l[i]*r[i];
        printf("%lld %lld\n",s2,s1);
    }
}

