 
 
 //地址: http://poj.org/problem?id=3250
 //题意:n头牛排成以行,从左到右,都面朝右,每头牛只能看到比自己矮的牛,问所有牛能看到的牛的总和为多少
 //题解:单调栈裸题,模拟一些即可
 
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
ll st[100010];
ll b[100010];
int main()
{
    int n;
    while(cin>>n)
    {
        int p=-1;
        for(int i=n;i>0;i--)rd(a[i]);
        a[0]=inf;
        memset(b,0,sizeof(b));
        for(int i=0;i<=n;i++)
        {
            while(p!=-1&&a[i]>a[st[p]]) {
                p--;
            }
            if(p==-1)b[i]=0;
            else b[i]=i-1-st[p];
            st[++p]=i;
        }
        ull sum=0;
        for(int i=0;i<=n;i++)
        {
//            bg(b[i]);
            sum+=b[i];
        }
        we(sum);
    }
}
