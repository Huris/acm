
//地址:https://www.luogu.org/problemnew/show/P1196
//题意:给你n个操作,有两种操作,一个操作是将第i列的元素全部移到第j列后面,另外一种操作是判断第i号元素与第j号元素是否在同一列
//题解:并查集,带边权
//代码:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define pii pair<int,int>


const int N=1e6+7;

int fa[N];
int d[N],siz[N];
char s[5];



int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=N;i++)
    {
        fa[i]=i;
        siz[i]=1;
    }
    int a,b;
    while(n--)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='M')
        {
            uni(a,b);
        }
        else
        {
            if(fi(a)==fi(b))printf("%d\n",abs(d[a]-d[b])-1);
            else printf("-1\n");
        }
    }
}
