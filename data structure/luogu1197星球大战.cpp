

//地址:https://www.luogu.org/problemnew/show/P1197
//题意:给你n个点的连通状况,然后断开k个点,每断开一次,求连通块数目
//题解:逆序并查集

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long


const int N=5e5+7;
int fa[N];
int fi(int x) {return fa[x]==x?x:fa[x]=fi(fa[x]);}
vector<int>mp[N];
int del[N];
int a[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)fa[i]=i;
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",a+i);
        del[a[i]]=1;
    }
    int gg=n-k; //初始有n-k个连通块,每个点都是一个连通块
    for(int i=0;i<n;i++)
    {
        if(del[i])continue; //如果遇到断开的点,就跳过
        for(int j=0;j<mp[i].size();j++) //遍历每条边
        {
            //如果不是一个连通块,并且该点不是断开点
            if(fi(i)!=fi(mp[i][j])&&del[mp[i][j]]==0)
            {
                gg--;     //合并,连通块数减1
                fa[fi(mp[i][j])]=fi(i);
            }
        }
    }
    stack<int>q;    //用栈倒序输出
    for(int i=k;i>=0;i--) //一共要输出k+1次,加上初始时的情况
    {
        del[a[i]]=0;    //把该点加上去
        q.push(gg);
        gg++;       //加上该点时,连通块数加1
        for(int j=0;j<mp[a[i]].size();j++)
        {
            if(fi(a[i])!=fi(mp[a[i]][j])&&del[mp[a[i]][j]]==0)
            {
                //如果属于同一个连通块并且不是断点,则连通块数减1
                gg--;   //合并连通块
                fa[fi(mp[a[i]][j])]=fi(a[i]);
            }
        }
    }
    while(q.size()) //依次输出连通块数目
    {
        printf("%d\n",q.top());
        q.pop();
    }
}
