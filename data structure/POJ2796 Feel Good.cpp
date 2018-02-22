

//地址:http://poj.org/problem?id=2796
//题意:给定n个数,求一个区间,该区间的最小值乘以区间和最大
//题解:单调栈,找出对一个数来说,左边界所有数都大于等于他,右边界所有数都大于等于他,然后用ans维护


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



ll a[100010];
ll st[100010];
ll sum[100010];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        int p=-1;
        ll ans=-1;
        int l,r;
        sum[0]=0;
        a[n+1]=-1;
        st[++p]=0;
        for(i=1;i<=n;i++)
        {
            rd(a[i]);
            sum[i]=sum[i-1]+a[i];
            while(p!=-1&&a[i]<a[st[p]])
            {
                if((sum[i-1]-sum[st[p-1]])*a[st[p]]>ans)
                {
                    ans=(sum[i-1]-sum[st[p-1]])*a[st[p]];
                    l=st[p-1]+1;
                    r=i-1;
                }
                p--;
            }
            st[++p]=i;
        }
        while(p!=-1)
        {
            if((sum[n]-sum[st[p-1]])*a[st[p]]>ans)
            {
                ans=(sum[i-1]-sum[st[p-1]])*a[st[p]];
                l=st[p-1]+1;
                r=i-1;
            }
            p--;
        }
        if(sum[n]==0)
        {
            printf("0\n1 %d\n",n);
        }
        else
        {
            printf("%lld\n%d %d\n",ans,l,r);

        }
    }

}
