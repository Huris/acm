

//地址:http://codeforces.com/contest/900/problem/D
//题意:问有多少种情况,使得gcd(a[1],a[2],...,a[k])=x,a[1]+a[2]+...+a[k]=y,输出所有情况对1e9+7取模
//题解:首先,如果x不能整除y,则输出0
       紧接着,令n=y/x,则题意转化为,有多少种情况,使得gcd(a[1],a[2],...,a[k])=1,a[1]+a[2]+...+a[k]=n
       如果不考虑最大公约数这个条件,则方法总数为poww(2,n-1)   ==>采用隔板法
       如果考虑第一个条件,则需要用到容斥原理,减去最大公约数为n的其他因子的情况,
       为了防止后效性,需要从后往前遍历
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


const ll mod=1e9+7;
ll poww(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)
            ans=ans*a%mod;
    }
    return ans;
}
ll dp[100010]={0};
ll fac[100010]={0};
int main()
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
    if(y%x==0)
    {
        ll z=y/x;
        int o=0;
        for(ll i=1;i*i<=z;i++)
        {
            if(z%i==0) {
                fac[o++]=i;
                if(i*i!=z)
                    fac[o++]=z/i;
            }
        }
        sort(fac,fac+o);
        for(int i=0;i<o;i++)
            dp[i]=poww(2,z/fac[i]-1);
        for(int i=o-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(fac[i]%fac[j]==0)
                    dp[j]=(dp[j]-dp[i]+mod)%mod;
            }
        }
        printf("%lld\n",dp[0]);
    }
    else printf("0\n");
}
