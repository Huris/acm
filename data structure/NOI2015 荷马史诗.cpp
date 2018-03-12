
//地址:https://www.luogu.org/problemnew/show/P2168
//题意:构造一颗Huffman树，求最小深度和最小代价。
//题解:huffman树模板题

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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define bg(x) cout<<x<<"@@@"<<endl
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
    ll w,h;
    node(ll ww,ll hh){w=ww;h=hh;}
    bool operator<(const node &k)const {
        return w!=k.w?w>k.w:h>k.h;
    }
};
int main()
{
    int n,k;
    ll x;
    scanf("%d%d",&n,&k);
    priority_queue<node>p;
    for(int i=0;i<n;i++)
    {
        rd(x);
        p.push(node(x,1));
    }
    while((p.size()-1)%(k-1)!=0)p.push(node(0,1));
    ll ans=0;
    while(p.size()>=k)
    {
        ll cnt=0,deep=-1;
        for(int i=0;i<k;i++)
        {
            cnt+=p.top().w;
            deep=max(deep,p.top().h);
            p.pop();
        }
        ans+=cnt;
        p.push(node(cnt,deep+1));
    }
    we(ans);
    we(p.top().h-1);
}
