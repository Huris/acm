

//地址:http://poj.org/problem?id=1456
//题意:给你n样物品,每样物品都有价值和过期时间,问可以获得的最大价值
//题解:1.二叉堆做法中,我们把商品按照过期时间从小到大排序,然后依次尝试用每个商品替换掉堆中利润较低的商品
       2.并查集做法
         贪心策略:按照价值从大到小排序,优先卖出价值大的商品,并且对每个商品,在他过期之前尽量晚卖出,
         占用较晚的时间,显然对其他商品具有"决策包容性"
         建立一个关于天数的并查集,起初每天各自构成一个集合,对于每个商品,若它在d天之后过期,就在并查集中查找d的树根(记为r)
         若r大于0,则把该商品安排在第r天卖出,合并r与r-1(令r为r-1的子节点),答案累加该商品的利润
         这个并查集实际上维护了一个数组中的"位置"的占用情况,每个"位置"所在集合的代表就是从它开始往前数第一个空闲的位置(包括它本身)
         当一个"位置"被占用时(某一天安排了商品),就把该"位置"在并查集中指向它前一个"位置",利用并查集的路径压缩,就可以快速找到最晚
         能卖出的时间(从过期时间往前数第一个空闲的时间)
         
//代码
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define pii pair<int,int>


const int N=1e6+7;

int fa[N];
int fi(int x)
{
    if(x==fa[x])return x;
    return fa[x]=fi(fa[x]);
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        priority_queue<pii >p;
        int v,d;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&v,&d);
            mx=max(mx,d);
            p.push(pii(v,d));
        }
        for(int i=0;i<=mx;i++)fa[i]=i;
        int sum=0;
        while(p.size())
        {
            pii now=p.top();p.pop();
            int z=fi(now.second);
            if(z==0)continue;
            sum+=now.first;
            fa[z]=fi(z-1);
        }
        printf("%d\n",sum);
    }
}
         
