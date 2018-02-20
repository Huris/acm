

//地址:http://poj.org/problem?id=1050
//题意:求子矩阵的最大和
//题解:二维前缀和

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

ll a[1003][1003];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                rd(a[i][j]);
                a[i][j]+=a[i][j-1];
            }
        ll sum,mx=-inf;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
            {
                sum=0;
                for(int k=1;k<=n;k++)
                {
                    sum+=a[k][j]-a[k][i-1];
                    mx=max(sum,mx);
                    if(sum<0)sum=0;
                }
            }
        we(mx);
    }

}
