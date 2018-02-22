

//地址:http://poj.org/problem?id=2259
//队列模拟题

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


int main()
{
    int n,z=1;
    while(scanf("%d",&n))
    {
        if(!n)break;
        map<int,int >mp;
        queue<int>q[1005];
        queue<int>qq;
        int i;
        int x,y;
        for(int i=1;i<=n;i++)
        {
            rd(x);
            while(x--)
            {
                rd(y);
                mp[y]=i;
            }
        }
        char s[20];
        printf("Scenario #%d\n",z++);
        while(scanf("%s",s))
        {
            if(strcmp(s,"STOP")==0)break;
            else if(strcmp(s,"ENQUEUE")==0)
            {
                rd(x);
                int pos=mp[x];
                if(q[pos].empty())
                    qq.push(pos);
                q[pos].push(x);
            }
            else
            {
                printf("%d\n",q[qq.front()].front());
                q[qq.front()].pop();
                if(q[qq.front()].empty())qq.pop();
            }
        }
        printf("\n");
    }
}
