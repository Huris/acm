

//地址:http://codeforces.com/problemset/problem/451/E
//题意:n个盒子,第i个盒子有a[i]朵花,同一个盒子的花颜色一样,不同盒子的花颜色不一样
       从这些盒子中选择m朵花,求共有多少种方案(若两束花每种颜色的花的数量都相同,则认为是同一种方案)
//题解:多重集的组合数模板题
//代码:
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>

const ll mod=1e9+7;
ll poww(ll a,ll b,ll c){ ll ans=1%c;for(a%=c;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}
ll inv[22];
ll a[50];
ll c(ll n,ll m)
{
    if(n<0||m<0||n<m)return 0;
    n%=mod;
    if(n==0||m==0)return 1;
    ll ans=1;
    for(ll i=0;i<m;i++)ans=ans*(n-i)%mod;
    for(ll i=1;i<=m;i++)ans=ans*inv[i]%mod;
    return ans;
}
int main()
{
    for(ll i=1;i<=20;i++)inv[i]=poww(i,mod-2,mod);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;i++)scanf("%lld",a+i);
    ll ans=0;
    for(ll i=0;i<1<<n;i++)
    {
        if(i==0)
        {
            ans=(ans+c(n+m-1,n-1))%mod;
            continue;
        }
        ll tmp=n+m;
        ll p=1;
        for(ll j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                p++;
                tmp-=a[j];
            }
        }
        tmp-=p;
        if(p&1)ans=(ans+c(tmp,n-1))%mod;
        else ans=(ans-c(tmp,n-1))%mod;
    }
    printf("%lld\n",(ans%mod+mod)%mod);
}
