
//地址:http://poj.org/problem?id=3349
//题意:给你n片雪花,两片雪花当且仅当顺时针或者逆时针元素一一对应相等才相等,求是否存在两片相等的雪花
//题解:hash每一片雪花然后判断是否相等
//用G++提交
代码:
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
#define vi vector<int>
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
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
    if(x<0)x=-x,putchar('-');wd(x);putchar(' ');
}


int n,tot,p=99991;
int snow[100010][6],head[100010],nex[100010];

int h(int a[])
{
    int s1=0,s2=1;
    rep(i,0,5)
    {
        s1=(s1+a[i])%p;
        s2=(ll)s2*a[i]%p;
    }
    return (s1+s2)%p;
}
bool eq(int a[],int b[])
{
    rep(i,0,5)
    {
        rep(j,0,5)
        {
            int e=1;
            rep(k,0,5)if(a[(i+k)%6]!=b[(j+k)%6])e=0;
            if (e)return 1;
            e=1;
            rep(k,0,5)if(a[(i+k)%6]!=b[(j-k+6)%6])e=0;
            if (e)return 1;
        }
    }
    return 0;
}
int ins(int a[])
{
    int val=h(a);   //遍历表头head[val]指向的链表,寻找形状相同的雪花
    for(int i=head[val];i;i=nex[i])
        if(eq(snow[i],a))return 1;
    memcpy(snow[++tot],a,6 * sizeof(int));
    nex[tot]=head[val];
    head[val]=tot;
    return 0;
}
int main()
{

    rd(n);
    rep(i,1,n)
    {
        int a[10];
        rep(j,0,5)rd(a[j]);
        if(ins(a))
        {
            printf("Twin snowflakes found.\n");
            return 0;
        }
    }
    printf("No two snowflakes are alike.\n");
}




