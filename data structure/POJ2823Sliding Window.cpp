

//地址:http://poj.org/problem?id=2823
//题意:给n个数,一个窗口,每次向右滑1个单位,求窗口的最大最小值
//题解:单调队列+读入输出优化      
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
    if(x<0)x=-x,putchar('-');wd(x);putchar(' ');
}



int sml[7000100];
int big[7000100];
int a[7000700];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        deque<int>mn,mx;
        int i,x;
        for(i=0;i<k-1;i++)
        {
            rd(a[i]);
            while(mn.size()&&a[i]<=a[mn.back()])mn.pop_back();
            while(mx.size()&&a[i]>=a[mx.back()])mx.pop_back();
            mn.push_back(i);
            mx.push_back(i);
        }
        int o=0;
        for(;i<n;i++)
        {
            rd(a[i]);
            while(mn.size()&&a[i]<=a[mn.back()])mn.pop_back();
            while(mx.size()&&a[i]>=a[mx.back()])mx.pop_back();
            mn.push_back(i);
            mx.push_back(i);
            while (i-mn.front()+1>k)mn.pop_front();
            while (i-mx.front()+1>k)mx.pop_front();
            big[o]=a[mx.front()];
            sml[o++]=a[mn.front()];
        }
        for (i=0;i<o-1;i++)
        {
           we(sml[i]);
        }
        printf("%d\n",sml[i]);
        for (i=0;i<o-1;i++)
        {
            we(big[i]);
        }
        printf("%d\n",big[i]);
    }
}
