

//地址:https://www.luogu.org/problemnew/show/P1072
//题意:有n个询问,每个询问中,先给四个自然数a,b,c,d,然后求有多少个x满足gcd(a,x)=b,lcm(c,x)=d
//题解:   gcd(a,x)=b; --> gcd(a/b,x/b)=1;
          lcm(c,x)=d; -->gcd(c,x)=c*x/d --> gcd(c/(c*x/d),x/(c*x/d))=gcd(d/x,d/c)=1;
          遍历d的因子i,如果i%b==0,并且满足上述两个最大公约数的等式,则ans++
          算出当前因子i后,在计算对应的那个d/i是否满足上述等式即可
//代码:
#include <cstdio>
#include <cstdlib>
#include <cstring>
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


int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int cnt=0;
        for(int i=1;i*i<=d;i++)
        {
            if(d%i==0)
            {
                if(i%b==0&&gcd(a/b,i/b)==1&&gcd(d/i,d/c)==1)cnt++;
                int ii=d/i;
                if(i==ii)continue;
                if(ii%b==0&&gcd(a/b,ii/b)==1&&gcd(d/ii,d/c)==1)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
