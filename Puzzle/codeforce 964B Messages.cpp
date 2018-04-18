


//地址:http://codeforces.com/problemset/problem/964/B
//题意:给你n封信,需要在t小时内读完,每封信的初始价值为a,
       1.如果一封信收到后不读,价值会减少b,但是会多c
       2.如果一封信收到后读了,可以获得当前价值,价值可为负
       问t小时后最多价值
//题解:比较b和c的大小,如果b大于等于c,则受到信后立马读,否则一直保持到最后一秒

//代码:
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long
#define pos(i,j) ((i-1)*m+j)



int t[2006];
int he[2006];
int main()
{
    int n,a,b,k,c;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&k);
    for(int i=0;i<n;i++)scanf("%d",t+i);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        if(c>b)
        {
            s+=(k-t[i])*c;
            s+=a-(k-t[i])*b;
        }
        else s+=a;
    }
    printf("%lld\n",s);
}
