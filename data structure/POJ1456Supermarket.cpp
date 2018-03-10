
//地址:http://poj.org/problem?id=1456
//题意:n个商品,给你过期时间和商品价值,求能够获得的最大价值
//题解:先对n个商品按照过期时间排序,然后弄一个优先队列,对每个商品,如果当前队列为空,则入队,如果队列元素比当前商品的过期时间小,
      则当前商品直接入队,如果当前商品过期时间等于队列元素个数,则比较堆顶元素价值和当前元素价值,如果比堆顶元素价值大,则先
      出队,后把当前元素入队
//代码:
#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <stack>
#include <stdlib.h>
#include <ctype.h>
#include <queue>
#include <bitset>
#include<cassert>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define bg(x) cout<<x<<"@@@"<<endl
template <typename T>inline void rd(T &x) {
    char c=getchar();int s=1;
    while(c!='-'&&!isdigit(c))c=getchar();
    if(c=='-')s=-1,x=0;else x=c-'0';
    while(c=getchar(),isdigit(c))x=x*10+c-'0';x*=s;
}
template <typename T>inline void wd(T x){
    if(x/10)wd(x/10);putchar(x%10+'0');
}
template <typename T>inline void we(T x){
    if(x<0)x=-x,putchar('-');wd(x);putchar('\n');
}


struct node
{
    int v,d;
    bool operator<(const node &k)const
    {
        return v>k.v;
    }
}e[100060];
bool cmp(node a,node b)
{
    return a.d<b.d;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) {
            rd(e[i].v);
            rd(e[i].d);
        }
        sort(e+1,e+1+n,cmp);
        priority_queue<node>pq;
        for(int i=1;i<=n;i++)
        {
            if(pq.empty())pq.push(e[i]);
            else if(pq.size()<e[i].d)pq.push(e[i]);
            else if(pq.size()==e[i].d)
            {
                if(pq.top().v<e[i].v)
                {
                    pq.pop();
                    pq.push(e[i]);
                }
            }
        }
        ll ans=0;
        while(pq.size())
        {
            ans+=pq.top().v;
            pq.pop();
        }
        we(ans);
    }
}
