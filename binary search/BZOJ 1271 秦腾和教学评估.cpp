
//题目说明:http://blog.csdn.net/Regina8023/article/details/43206249
//提交地址:http://begin.lydsy.com/JudgeOnline/problem.php?id=4725

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



ll s[200010],e[200010],d[200200];
int main()
{
    ll t;
    rd(t);
    while(t--)
    {
        ll n;
        rd(n);
        ll mx=-1;
        for(ll i=0;i<n;i++)scanf("%lld%lld%lld",s+i,e+i,d+i);
        ll l=0,r=0x7fffffff;
        ll now,i;
        while(l<r)
        {
            ll mid=l+r>>1;
            for(now=0,i=0;i<n;i++)
                if(mid>=s[i])
                   now+=(min(mid,e[i])-s[i])/d[i]+1;
            if (now&1)r=mid;else l=mid+1;
        }
        ll ans=0;
        for(i=0;i<n;i++)
        {
            if(l>=s[i]&&l<=e[i]&&(l-s[i])%d[i]==0)
                ans++;
        }
        if(ans&1)printf("%lld %lld\n",l,ans);
        else puts("Poor QIN Teng:(");
    }
}
