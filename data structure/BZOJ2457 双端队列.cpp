

//地址:http://www.lydsy.com/JudgeOnline/problem.php?id=2457
//题意:Sherry现在碰到了一个棘手的问题，有Ｎ个整数需要排序。
       Sherry手头能用的工具就是若干个双端队列。
       她需要依次处理这N个数，对于每个数，Sherry能做以下两件事：
          1．新建一个双端队列，并将当前数作为这个队列中的唯一的数；
          2．将当前数放入已有的队列的头之前或者尾之后。
       对所有的数处理完成之后，Sherry将这些队列排序后就可以得到一个非降的序列。
//题解:先对整个数组排序,然后易得一个结论,当排序后的序列的原始坐标满足单谷性质,需要一个双端队列,然后统计即可
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
    int val;
    int i;
    bool operator<(const node &k)const
    {
        return val!=k.val?val<k.val:i<k.i;
    }
}d[200200];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        rd(d[i].val);
        d[i].i=i;
    }
    sort(d+1,d+n+1);
    int mn=0,mx=0;
    int now=inf;
    int j,f=1;
    int ans=0;
    for(i=1;i<n;i++)
    {
        mn=d[i].i;
        for(j=i;j<n;j++)
        {
            if(d[j].val!=d[j+1].val)
                break;
        }
        mx=d[j].i;
        if(f==-1)
        {
            if(mx<now)now=mn;
            else now=mx,f=1;
        }
        else
        {
            if(mn>now)now=mx;
            else {
                ans++;
                f=-1;
                now=mn;
            }
        }
        i=j;
    }
    we(ans);
}
