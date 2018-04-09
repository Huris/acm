

//地址:http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=5747
//题意:给你n个a型背包,m个b型背包,每个型号的背包价值是一样的,但是重量是不一样的,
       规定将物品装入包中的价值为value=k1*(c-sa[i])
       求最大装包价值
//题解:根据题意分析,每一类背包的价值是一样的,所以优先选择体积小的背包,所以对两类
        来说也是大趋势是体积小的优先,所以我们可以从小到大枚举a,b类的任意两个区间,
        只要这两个区间的体积和小于总容量就行,但是a,b类的物品顺序还有影响,
        我们用dp[i][j]代表枚举a类的1~i区间,b类的1~j区间,
        状态转移方程为dp[i][j]=max(dp[i-1][j]+k1*(c-s),dp[i][j-1]+k2*(c-s));
        表示我们可以先放a类的第i个物品,或者先放b类的第j个物品
        取二者的最大值
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


ll dp[2002][2002];
ll sa[2002],sb[2002];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        ll k1, k2, c;
        int n, m;
        scanf("%lld%lld%lld", &k1, &k2, &c);
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = 0;
        for (int i = 1; i <= n; i++)scanf("%lld", sa + i);
        for (int i = 1; i <= m; i++)scanf("%lld", sb + i);
        sort(sa + 1, sa + 1+n); sort(sb + 1,sb + 1 + m);
        for (int i = 1; i <= n; i++)sa[i] += sa[i - 1];
        for (int i = 1; i <= m; i++)sb[i] += sb[i - 1];
        ll ans=0;
        for(int i=1;i<=n&&sa[i]<=c;i++)
        {
            ans=max(ans,dp[i][0]=k1*(c-sa[i])+dp[i-1][0]);
        }
        for(int i=1;i<=m&&sb[i]<=c;i++)
        {
            ans=max(ans,dp[0][i]=k2*(c-sb[i])+dp[0][i-1]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ll s=sa[i]+sb[j];
                if(s<=c)
                {
                    ans=max(ans,dp[i][j]=max(dp[i-1][j]+k1*(c-s),dp[i][j-1]+k2*(c-s)));
                }
            }
        }

        printf("%lld\n",ans);
    }
}
