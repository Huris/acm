

//地址:https://www.lydsy.com/JudgeOnline/problem.php?id=2440
//题意:求出第n个不包含完全平方因子的数
//题解:莫比乌斯函数+二分
//代码:
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
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



const int N=1e5+7;
const int maxl=1e5;
int p[N],prime[N],mu[N];
void init()
{
    mu[1]=1;
    for(int i=2;i<=maxl;i++){
        if(!p[i]){
            prime[++prime[0]]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=prime[0]&&i*prime[j]<=maxl;j++){
            p[i*prime[j]]=true;
            if(i%prime[j])mu[i*prime[j]]=-mu[i];
            else{
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
}
ll check(ll x)
{
    ll ans=0;
    for(ll i=1;i*i<=x;i++)
        ans+=x/(i*i)*mu[i];
    return ans;
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        rd(n);
        ll l=n,r=n<<1;
        while(l<r)
        {
            ll mid=l+r>>1;
            if(check(mid)>=n)r=mid;
            else l=mid+1;
        }
        we(l);
    }
}
