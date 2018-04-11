


//地址:http://poj.org/problem?id=3090
//题意:在一个平面直角坐标系的以(0,0)为左下角,(n,n)为右上角的矩形中,除了(0,0)之外.每个坐标上都
       插着一枚钉子
       求在原点向四周看去,能够看到多少个钉子,一个钉子能被看到当且仅当连接它和原点的线段上没有其他钉子
//题解:分析题目容易发现,除了(1,0),(0,1)和(1,1)这三个钉子外,一个钉子(x,y)能被看到当且仅当1<=x,y<=n,x!=y并且gcd(x,y)=1
       在1<=x,y<=n,x!=y中能看到的钉子关于直线(0,0),(n,n)对称,我们可以考虑其中的一半,即1<=x<y<=n
       换言之,对于每个2<=y<=n,我们需要统计有多少个x满足1<=x<y并且gcd(x,y)=1,这样的x的数量恰好是φ(y)
       综上所述,本题的答案就是3+2∑φ(i)
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


const int N=1e5+7;
int prime[N],phi[N];
void init()
{
    prime[1]=phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!prime[i]){prime[++prime[0]]=i;phi[i]=i-1;}
        for(int j=1;j<=prime[0]&&prime[j]*i<N;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j])phi[prime[j]*i]=phi[i]*(prime[j]-1);
            else {phi[prime[j]*i]=phi[i]*prime[j];break;}
        }
    }
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=2;i<=n;i++)sum+=phi[i];
        printf("%d %d %d\n",z,n,2*sum+3);
    }
}
