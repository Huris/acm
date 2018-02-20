

//地址:http://poj.org/problem?id=2083
//题意:求n级分形图
//题解:套模板

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


string s[3];
char mp[3002][3002];
int poww(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=a*a)if(b&1)ans*=a;
    return ans;
}
void dfs(int n,int x,int y)
{
    int i,j;
    if(n==1)
    {
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                mp[x+i][y+j]=s[i][j];
        return;
    }
    int nr=poww(3,n-1);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(s[i][j]!=' ')
                dfs(n-1,x+i*nr,y+j*nr);

}
int main()
{
    s[0]="X X";
    s[1]=" X ";
    s[2]="X X";
    int n;
    while(scanf("%d",&n))
    {
        if(n==-1)break;
        n--;
        if(n==0)
        {
            printf("X\n-\n");
            continue;
        }
        int r=poww(3,n);
        for(int i=0;i<r;i++)
            for(int j=0;j<r;j++)
                mp[i][j]=' ';
        dfs(n,0,0);
        for(int i=0;i<r;i++)
            for(int j=r-1;j>=0;j--)
                if(mp[i][j]!=' ')
                {
                    mp[i][j+1]='\0';
                    break;
                }
        for(int i=0;i<r;i++)
            puts(mp[i]);
        printf("-\n");
    }
}
