

//地址:http://poj.org/problem?id=2689
//题意:给两个整数L,R (1<=L<=R<=2,147,483,647  R-L<=1e6),求闭区间[L,R]中相邻两个质数差最大是多少,输出这两个质数
//题解:L,R的范围会很大,任何已知的算法都无法再规定的时间内生成[1,R]中的所有质数,但R-L的范围很小,并且任何一个合数n必定包含一个不超过sqrt(R)的质因子
       所以,我们只需要用筛法求出2~sqrt(R)的所有质数,对于每个质数p,把[L,R]中能被p整除的数标记,即标记i*p( L/p <= i <= R/p )为合数
       最终所有未被标记的数就是[L,R]中的质数,对相邻的质数进行两两比较,找出差最大的即可
       时间复杂度O(sqrt(R)+(R-L))
//代码
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long



const int N=1000006;
int prime[1000040];
int a[N];
int b[N];
void init()
{
    for(int i=2;i<=N;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    init();
    int l,r;
    while(~scanf("%d%d",&l,&r))
    {
        int i,j;
        memset(a,0,sizeof(a));
        if(l==1)l++;
        int rr=sqrt(r);
        for(i=1;prime[i]<=rr;i++)
        {
            for(j=ceil(1.0*l/prime[i]);j<=1.0*r/prime[i];j++)
            {
                if(j==1)j++;
                a[j*prime[i]-l]=1;
            }
        }
        int o=0;
        for(i=0;i<=r-l;i++)if(a[i]==0)b[o++]=i;
//        for(i=0;i<o;i++)
//        printf("%d\n",b[i]+l);
        if(o<2)printf("There are no adjacent primes.\n");
        else
        {
            int mx=1,mn=1;
            for(i=2;i<o;i++)
            {
                if((b[mx]-b[mx-1])<(b[i]-b[i-1]))mx=i;
                if((b[mn]-b[mn-1])>(b[i]-b[i-1]))mn=i;
//                printf("%d %d\n",mn,mx);
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",b[mn-1]+l,b[mn]+l,b[mx-1]+l,b[mx]+l);
        }

    }
}
