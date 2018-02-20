


//地址:http://poj.org/problem?id=3714
//给定两个不同集合,求两个集合各取一个点距离最小


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
#define ull unsigned long long
#define PI acos(-1.0)
#define E 2.7182818284590452353602874713527
#define bg(x) cout<<x<<"@@@"<<endl
#define lowbit(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
#define pii pair<int,int>
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


const int N=1e6+7;
struct node
{
    double x,y;
    int f;
}e[2*N];
bool cmp(node a,node b)
{
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}
bool cmp1(node a,node b)
{
    return a.y<b.y;
}
double dis(node a,node b)
{
    if(a.f==b.f)return inf;
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mn_dis(int l,int r)
{
    if(l==r)return 1.0*inf;
    if(l+1==r)return dis(e[l],e[r]);
    int mid=l+r>>1;
    double ans=min(mn_dis(l,mid),mn_dis(mid+1,r));
    int i,j;
    vector<node>q;
    for(i=l;i<=r;i++)
        if(fabs(e[i].x-e[mid].x)<=ans)
            q.push_back(e[i]);
    sort(q.begin(),q.end(),cmp1);
    for(i=0;i<q.size();i++)
        for(j=i+1;j<q.size();j++)
            if(q[j].y-q[i].y<=ans)
                ans=min(dis(q[j],q[i]),ans);
            else break;
    return ans;
}
int main()
{

    int t;
    rd(t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)scanf("%lf%lf",&e[i].x,&e[i].y),e[i].f=0;
        for(;i<2*n;i++)scanf("%lf%lf",&e[i].x,&e[i].y),e[i].f=1;
        sort(e,e+2*n,cmp);
        printf("%.3f\n",mn_dis(0,2*n-1));
    }
}
