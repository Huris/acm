


//地址:http://acm.hdu.edu.cn/showproblem.php?pid=1506
//题意:求最大矩形面积
//题解:单调栈,如果当前高度比栈顶元素小,则弹出栈顶,维护最大值,一直保持栈为非递减栈,
//      一个技巧,设最后一个元素的下一个元素的高度为0,这样可以保证最后栈清空
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



ll a[100010];
ll h[100010];
ll w[100010];
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)break;
        ll mx=-1;
        int p=-1;
        for(int i=0;i<n;i++)rd(h[i]),w[i]=1;
        h[n]=0;
        for(int i=0;i<=n;i++)
        {
            if(p==-1||h[i]>h[a[p]])
            {
                a[++p]=i;
            }
            else
            {
                int width=0;
                while(p!=-1&&h[i]<=h[a[p]])
                {
                    width+=w[a[p]];
                    mx=max(mx,h[a[p]]*width);
                    p--;
                }
                w[i]+=width;
                a[++p]=i;
            }
        }
        we(mx);
    }
}
