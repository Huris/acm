

//地址:http://codevs.cn/problem/4228/
//题意:n头猫下山,每只猫体重为c[i],每个缆车最多承载w,问最少需要多少缆车
//题解:dfs搜索

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f

int a[30];
int n,w;
int vis[30];
bool cmp(int a,int b)
{
    return a>b;
}
int mx;
void dfs(int i,int cnt)
{
    if(cnt>=mx)return;
    if(i==n){
//        printf("%d!!\n",cnt);
        mx=min(cnt,mx);
        return;
    }
    for(int j=1;j<=cnt;j++)
    {
        if(vis[j]+a[i]<=w)
        {
            vis[j]+=a[i];
            dfs(i+1,cnt);
            vis[j]-=a[i];
        }
    }
    vis[cnt+1]+=a[i];
    dfs(i+1,cnt+1);
    vis[cnt+1]=0;
}
int main()
{
    while(~scanf("%d%d",&n,&w))
    {
        mx=n;
        memset(vis,0,sizeof(0));
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n,cmp);
        dfs(0,0);
        printf("%d\n",mx);
    }
}


