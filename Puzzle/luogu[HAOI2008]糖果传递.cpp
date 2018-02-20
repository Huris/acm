

//地址:https://www.luogu.org/problemnew/show/P2512
//题意:有n个小朋友坐成一圈，每人有ai个糖果。每人只能给左右两人传递糖果。每人每次传递一个糖果代价为1。求每个人获得均等糖果的最小代价
//题解:裸环形均分纸牌问题

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

ll f(ll x)
{
    return x>0?x:-x;
}
ll a[1000100];
int main()
{
    ll n;
    rd(n);
    ll sum=0;
    for(int i=1;i<=n;i++)rd(a[i]),sum+=a[i];
    sum/=n;
    for(int i=1;i<=n;i++)a[i]+=a[i-1]-sum;
    ll m=n+1>>1;
    nth_element(a+1,a+m,a+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=f(a[i]-a[m]);
    we(ans);
}
