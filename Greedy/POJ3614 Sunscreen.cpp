

//地址:http://poj.org/problem?id=3614
//题意:给定牛的min和max晒太阳区间,给定护晒霜的val和数目,求最多有几头牛可以舒服晒太阳
//题解:对每头牛按照min从大到小排序,然后对每头牛,使用符合区间的最高val的护晒霜

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


int a[3000];
int main()
{
    int c,l;
    while(cin>>c>>l) {
        int i;
        memset(a,0,sizeof(a));
        priority_queue<pii>q;
        int x,y;
        for(i=0;i<c;i++)
        {
            rd(x);rd(y);
            q.push(pii(x,y));
        }
        for(i=0;i<l;i++)
        {
            rd(x);rd(y);
            a[x]+=y;
        }
        int s=0;
        while(q.size())
        {
            pii now=q.top();q.pop();
            for(i=now.second;i>=now.first;i--)
                if(a[i])
                {
                    a[i]--;
                    s++;
                    break;
                }
        }
        we(s);
    }
}
