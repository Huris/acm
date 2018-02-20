

//地址:https://www.luogu.org/problemnew/show/P2862
//题意:给定若干个点,求最小的正方形,包含c个点
//题解:第一步还是对答案二分，但在横坐标的枚举上，我们可以简化一下
//    直接枚举每个区间[N, N + mid][N,N+mid] ，这样就少了两个指针。那么怎么统计出这个区间内最大的点数目呢？
//    首先我们另外开一个数组，维护以纵坐标为第一关键字、横坐标为第二关键字排序的点。
//    然后我们对这个数组进行一次遍历，可以取出所有符合条件的点的纵坐标，并存在一个新数组m中。
//    这样，m中保存的就是横坐标在区间[N, N + mid][N,N+mid] 内所有点以纵坐标排序的结果。
//    这个时候，我们将p1p2作为两个指针指向数组m的最前面，然后首先将p2滚动到离p1最远的符合条件的位置。
//    这样的话就很舒适了，我们不断的滚动p2，并修改p1使之符合条件，直到p2到达m的最后一个元素。
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


struct node
{
    int x,y;
}a[503],b[503];
bool cmp1(node a,node b)
{
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}
bool cmp2(node a,node b)
{
    return a.y!=b.y?a.y<b.y:a.x<b.x;
}
int e,n;

int getcnt(int l,int mid)
{
    int r=l+mid-1;
    int cnt=0;
    int m[505];
    for(int i=1;i<=n;i++)
    {
        if(b[i].x>=l&&b[i].x<=r)
            m[cnt++]=b[i].y;
    }
    int p1=0,p2=0;
    while(m[p2]-m[p1]+1<=mid&&p2<cnt)p2++;
    p2--;   //p2要减1,即p2为满足条件下的最大
    int ans=-1;
    while(p1<=p2&&p2<cnt)  //尺取法
    {
        ans=max(ans,p2-p1+1);  //p2 - p1 + 1就是包含的点数
        p2++;
        while(m[p2]-m[p1]+1>mid&&p1<=p2)p1++; //根据p2滚动p1
    }
    return ans;
}
int check(int mid)  //枚举每一个点并求出[L, L + mid]的最大点数
{
    for(int i=1;i<=n;i++)
        if(getcnt(a[i].x,mid)>=e)
            return 1;
    return 0;
}
int main()
{
     rd(e);rd(n);
    for(int i=1;i<=n;i++)
    {
        rd(a[i].x);rd(a[i].y);
        b[i]=a[i];
    }
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+n+1,cmp2);
    int l=0,r=10004;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid))r=mid;else l=mid+1;
    }
    we(l);
}
