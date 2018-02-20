

//地址:http://poj.org/problem?id=1328
//题意:给定若干个点,给定半径,求最少需要多少个圆可以覆盖所有点
//题解:对每个点,求出可以覆盖它的点的区间,然后根据区间重合,贪心最小圆的数目

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
#define pii pair<double,double>
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


const double eps=1e-8;
double dis(pii a,pii b)
{
    return  sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int main()
{
    int n,k=1;
    double d;
    while(scanf("%d%lf",&n,&d))
    {
        if(n==0&&d==0)break;
        priority_queue<pii,vector<pii>,greater<pii> >q;
        double x,y;
        int f=1;
        while(n--)
        {
            scanf("%lf%lf",&x,&y);
            if(y>d)f=0;
            double z=sqrt(d*d-y*y);
            q.push(pii(x-z,x+z));
        }
        printf("Case %d: ",k++);
        if(!f)
        {
            printf("-1\n");
            continue;
        }
        int s=1;
        double nx;
        pii now=q.top();q.pop();
        nx=now.second;
        while(q.size())
        {
            now=q.top();q.pop();
            if(now.first>nx)
            {
                s++;
                nx=now.second;
            }
            else
            {
                nx=min(nx,now.second);
            }
        }
        we(s);
    }
}
