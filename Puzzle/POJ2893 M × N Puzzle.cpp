

//地址:http://poj.org/problem?id=2893
//题意:给定M*N数码的1个形式,判断该形式能否变成正确顺序
//题解:两个数码的逆序数加上0所在的行列如果相等,即可变

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
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define E 2.7182818284590452353602874713527
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define bg(x) cout<<x<<"@@@"<<endl
#define lowbit(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
#define pii pair<int,int>
template <class T>inline void rd(T &x) {
    char c=getchar();int s=1;
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')s=-1,x=0;else x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';x*=s;
}



ll cnt;
int a[1000100];
int tmp[1000100];
void merge(int l,int r)
{
    if(l==r)return;
    int mid=l+r>>1;
    merge(l,mid);
    merge(mid+1,r);
    int i=l,j=mid+1;
    for(int k=l;k<=r;k++)
        if(j>r||i<=mid&&a[i]<a[j])tmp[k]=a[i++];
    else tmp[k]=a[j++],cnt+=mid+1-i;
    for(int k=l;k<=r;k++)a[k]=tmp[k];
}
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        cnt=0;
        int i,j;
        int x,y,z,o=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                rd(a[o]);
                if(!a[o++]){
                    x=i;
                    y=j;
                }
            }
        }
        merge(0,n*m-1);
        if((cnt+x+y)%2==(n-1+m-1+n*m-1)%2)puts("YES");
        else puts("NO");
    }
}
