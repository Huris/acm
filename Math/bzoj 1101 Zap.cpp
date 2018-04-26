

//地址:https://begin.lydsy.com/JudgeOnline/problem.php?id=4807
//题意:50000组询问,每次询问给3个整数a,b,k,求有多少对二元组(x,y),满足x<=a,y<=b并且gcd(x,y)=k
//题解:莫比乌斯反演裸题

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


const int N=1e6+7;
int p[N],pri[N],mu[N];
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!p[i]){pri[++pri[0]]=i;mu[i]=-1;}
        for(int j=1;j<=pri[0]&&pri[j]*i<N;j++)
        {
            p[pri[j]*i]=1;
            if(i%pri[j])mu[i*pri[j]]=-mu[i];
            else {
                mu[i*pri[j]]=0;
                break;
            }
        }
    }
}
int main()
{
    init();
    for(int i=1;i<N;i++)mu[i]+=mu[i-1];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        a/=d;b/=d;
        int ans=0,nex;
        for(int i=1;i<=min(a,b);i=nex+1)
        {
            nex=min(a/(a/i),b/(b/i));
            ans+=(a/i)*(b/i)*(mu[nex]-mu[i-1]);
        }
        printf("%d\n",ans);
    }
}
