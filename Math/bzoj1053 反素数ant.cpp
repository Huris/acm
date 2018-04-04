

//地址:https://www.lydsy.com/JudgeOnline/problem.php?id=1053
//题意:求不超过n的约数最多的最小那个数
//题解:DFS+数学
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


ll prime[15]={2,3,5,7,11,13,17,19,23,29,31};
ll ans,num,n;
void dfs(int k,ll now,int cnt,int last)//第几个质数,从开始到现在质数的乘积,质数个数,质数幂的次数
{
    if(k==9)
    {
        if(now>ans&&cnt>num){ans=now;num=cnt;}
        if(now<=ans&&cnt>=num){ans=now;num=cnt;}
        return;
    }
    int t=1;
    for(int i=0;i<=last;i++)
    {
        dfs(k+1,now*t,cnt*(i+1),i);
        t*=prime[k];
        if(now*t>n)break;
    }
}
int main()
{
    scanf("%lld",&n);
    dfs(0,1,1,30);
    printf("%lld\n",ans);
}
