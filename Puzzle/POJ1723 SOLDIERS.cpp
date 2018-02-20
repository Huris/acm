

//地址:http://poj.org/problem?id=1723
//题意:平面上给n个坐标,每个点每次只能上下左右移动一个单位,求把这n个点连成一条水平线最少需要移动几次
//题解: 货仓选址问题  
        1.对于y方向,按照从小到大排序,最小移动次数为所有数与中位数之差绝对值的和 s1
        2.对于x方向,根据1,所有点都在一条水平线上了,但是有些位置上的士兵重叠了,可按照下述方法操作
          a.把所有的x从小到大排序,设最优解是横坐标位置为  k,k+1,k+2...k+n
          b.我们要求的是移动步数,即  sum=|x0-k|+|x1-(k+1)|+|x2-(k+2)|+...+|xn-(k+n)|
                                      =|(x0-0)-k|+|(x1-1)-k|+|(x2-2)-k|+...+|(xn-n)-k|
          c.又转化为货仓选址问题,找中位数,然后做差求绝对值之和 s2
        3.最后答案为 s=s1+s2
//代码
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


ll f(ll x)
{
    return x>0?x:-x;
}
int a[100010],b[100010];
int main()
{
    int n;
    while(cin>>n) {
        int i;
        for(i=0;i<n;i++)rd(a[i]),rd(b[i]);
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)a[i]-=i;
        sort(a,a+n);
        ll ans=0;
        ll m=n>>1;
        for(i=0;i<n;i++)ans+=f(b[i]-b[m])+f(a[i]-a[m]);
        we(ans);
    }
}
