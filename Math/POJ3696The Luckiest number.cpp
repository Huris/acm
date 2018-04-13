

//地址:http://poj.org/problem?id=3696
//题意:给定一个正整数n,n<=2e9,问至少多少个8连在一起组成的正整数是n的倍数
//题解:x个8连在一起组成的正整数可以写作8(10^x-1)/9,题目就是让我们求出一个最小的x,满足n丨8(10^x-1)/9
       设d=gcd(n,8)
       n丨8(10^x-1)/9  <==> 9n丨8(10^x-1) <==> 9n/d丨10^x-1  <==> 10^x = 1 (mod 9n/d)
      引理:若正整数a,n互质,则满足a^x=1(mod n)的最小正整数x0是φ(n)的约数
      证明:反证法,设满足a^x=1(mod n)的最小正整数x0不能整除φ(n)
           设φ(n)=qx0+r(0<r<x0),因为a^x0=1(mod n),故a^qx0=1(mod n),
           根据欧拉定理a^φ(n)=1(mod n),所以a^r=1(mod n),这与x0最小矛盾
           故假设不成立,原命题成立
           证毕.
      根据以上引理,我们只需求出欧拉函数φ(9n/d),枚举它的所有约数,用快速幂逐一检查是否满足条件即可
      时间复杂度O(sqrt(n)logn)
          
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


ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll mul(ll a,ll b,ll c)
{
    ll l=a*(b>>25)%c*(1<<25)%c;
    ll r=a*(b&((1<<25)-1))%c;
    return (l+r)%c;
}

ll euler(ll n)
{
    ll a=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a=a/i*(i-1);
            while(n%i==0)n/=i;
        }

    }
    if(n>1)a=a/n*(n-1);
    return a;
}
ll poww(ll a,ll b,ll c)
{
    ll ans=1%c;
    for(a%=c;b;b>>=1,a=mul(a,a,c)){
        if(b&1)
            ans=mul(ans,a,c);
    }
    return ans;
}
int main()
{
    ll n;
    int k=1;
    while(~scanf("%lld",&n))
    {
        if(!n)break;
        ll d=gcd(n,8);
        ll m=9*n/d;
        printf("Case %d: ",k++);
        if(gcd(10,m)==1)
        {
            ll z=euler(m);
            ll i;
            ll w=z;
            int f=0;
            for(i=1;i*i<=z;i++)
            {
                if(z%i==0&&poww(10,i,m)==1)
                {
                    w=i;f=1;
                    break;
                }
            }
            if(!f)
            for(i=(ll)sqrt(z);i>=2;i--)
            {
                if(z%i==0&&poww(10,z/i,m)==1)
                {
                    w=z/i;
                    break;
                }
            }

            printf("%lld\n",w);
        }
        else printf("0\n");
    }
}


