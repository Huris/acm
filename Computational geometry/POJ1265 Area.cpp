

//地址:http://poj.org/problem?id=1265
//题意:给你一个多边形,求多边形边上的点,内部的点,还有多边形的面积
//题解:Pick定理：一个计算点阵中顶点在格点上的多边形面积公式：S=a+b/2-1，其中a表示多边形内部的点数，b表示多边形边界上的点数，S表示多边形的面积。 
      那么a=(2S-b+2)/2 
      S可以通过叉积求出 
      计算b的方法是：某一条边(x,y)上的整点的数量是gcd(|x|,|y|)+1


//代码
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
ll poww(ll a,ll b,ll c){ll ans=1%c;for(a%=c;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}


int n,x,y,nx,ny,S,a,b;
struct point
{
    int x,y;
    point(int xx=0,int yy=0){ x=xx,y=yy; }
}e[205];
point operator - (point a,point b) { return point(a.x-b.x,a.y-b.y);}
int _abs(int x) { return x>0?x:-x; }
int Cross(point a,point b) { return a.x*b.y-a.y*b.x;}//计算叉积
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
int Area()  //计算面积
{
    int area=0;
    for (int i=2;i<n;++i)   //计算多边形面积
        area+=Cross(e[i]-e[1],e[i+1]-e[1]);
    return _abs(area);
}
int calc(point a) {return gcd(_abs(a.x),_abs(a.y)); }  //计算边上的顶点数
int main()
{
    int t,k=1;
    scanf("%d",&t);
    while (t--)
    {
        S=a=b=0;nx=ny=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            nx+=x,ny+=y;
            e[i]=point(nx,ny);
        }
        S=Area();
        for (int i=1;i<=n;++i)
            b+=calc(e[i]-e[i%n+1]);
        a=(S-b+2)/2;
        printf("Scenario #%d:\n",k++);
        printf("%d %d %d",a,b,S/2);
        if (S&1) printf(".5\n");
        else printf(".0\n");
        printf("\n");
    }
}
