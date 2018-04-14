

//地址:http://poj.org/problem?id=1845
//题意:求a^b所有约数之和mod9901
//题解:根据约数之和,通过等比公式相乘可以算出约数之和
        考虑两个方面:
        1.p-1是p的倍数,则
          p=1(mod p)
          因此 1+p+p^2+...+p^k (mod p)= 1+1+1+1+...+1  (mod p)= k+1  (mod p)
        2.p-1不是p的倍数,则
        直接费马小定理计算逆元
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


const ll mod=9901;
ll p[100];
ll c[100];
ll poww(ll a,ll b,ll c)
{
    ll ans=1%c;
    for(a%=c;b;b>>=1,a=a*a%c)
    {
        if(b&1)
            ans=ans*a%c;
    }
    return ans;
}
int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        memset(c,0, sizeof(c));
        int o=0;
        for(ll i=2;i*i<=a;i++)
        {
            if(a%i==0)
            {
                while(a%i==0)
                {
                    p[o]=i;
                    c[o]++;
                    a/=i;
                }
                c[o]*=b;
                o++;
            }
        }
        if(a>1)p[o]=a,c[o++]=b;
        ll ans=1;
        for(int i=0;i<o;i++)
        {
            ll tmp=p[i]-1;
            if(tmp%mod==0)
            {
                ans=ans*(c[i]+1)%mod;
            }
            else
            {
                ans=ans*poww(p[i]-1,mod-2,mod)%mod*(poww(p[i],c[i]+1,mod)-1)%mod;

            }
        }
        printf("%lld\n",(ans%mod+mod)%mod);
    }
}
