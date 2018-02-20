
//地址:http://poj.org/problem?id=3190
//题意:安排牛的产奶,每头牛给定初始产奶时间和结束产奶时间,求最少需要几个产奶房以及每头牛安排在哪个产奶房
//题解:贪心,每头牛按照产奶初始时间从小到大排序,然后根据区间不重叠数进行贪心

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
    int x,y,i;
    bool operator<(const node &k)const
    {
        return x<k.x;
    }
}d[50050];
int tmp[50030];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        priority_queue<pii,vector<pii>,greater<pii> >niu;
        int i,x,y;
        for(i=1;i<=n;i++){rd(d[i].x);rd(d[i].y);d[i].i=i;}
        sort(d+1,d+1+n);
        int s=1,o=1;
        tmp[d[1].i]=s;
        niu.push(pii(d[1].y,s));
        tmp[o++]=s;
        for(i=2;i<=n;i++)
        {
            if(d[i].x>niu.top().first)
            {
                tmp[d[i].i]=niu.top().second;
                niu.push(pii(d[i].y,niu.top().second));
                niu.pop();
            }
            else
            {
                s++;
                tmp[d[i].i]=s;
                niu.push(pii(d[i].y,s));
            }
        }
        we(s);
        for(i=1;i<=n;i++)we(tmp[i]);
    }
}
