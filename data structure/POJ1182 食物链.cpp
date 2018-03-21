


//地址:http://poj.org/problem?id=1182
//题意:给你k个语句,判断有几句假话
//题解:并查集,扩展域
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


const int N=3e5+7;
int n,k;
int fa[N];

int fi(int x)
{
    if(x==fa[x])return x;
    return fa[x]=fi(fa[x]);
}

int main()
{
        scanf("%d%d",&n,&k);

        for(int i=1;i<=n*3;i++)fa[i]=i;
        int sum=0;
        int a,b,c;
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            int bb=b+n,cc=c+n;
            int bbb=bb+n,ccc=cc+n;
            if(b>n||c>n)
            {
                sum++;
                continue;
            }
            if(a==1)
            {
                if(fi(bb)==fi(c)||fi(b)==fi(cc))
                {
                    sum++;
                    continue;
                }
                fa[fi(b)]=fi(c);
                fa[fi(bb)]=fi(cc);
                fa[fi(bbb)]=fi(ccc);
            }
            else
            {
                if(b==c||fi(b)==fi(c)||fi(b)==fi(cc))
                {
                    sum++;
                    continue;
                }
                fa[fi(bb)]=fi(c);
                fa[fi(b)]=fi(ccc);
                fa[fi(bbb)]=fi(cc);
            }
        }
        printf("%d\n",sum);
    }



