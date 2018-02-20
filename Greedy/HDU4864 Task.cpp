

//地址:http://acm.hdu.edu.cn/showproblem.php?pid=4864
//题意:有n个任务，m台机器，每个任务需要xi的时间去做，且难度为y，做完后会得到500*xi+2*yi的钱；
       每台机器也有一个使用时间上限xi以及机器的能力yi，一台机器可以完成一个任务仅当机器的x，y都大于任务的，现在每台机器只能做一个任务。
       求最大完成任务数量以及得到钱的最大值。
//题解:通过数据可以发现，时间差造成的钱的影响远大于难度差造成的影响，所以我们要优先完成时间长的任务，
       我们将任务和机器均按照时间排序。从时间最长的任务开始选取，同时按照难度维护所有时间上限不低于当前任务的所有机器，
       D[i]表示难度为i的且时间上限不低于当前任务的机器数量，然后按照难度从小到大来选取完成当前任务的机器即可。
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


struct node
{
    int time,leval;
    bool operator<(const node &k)const {
        if(time!=k.time)return time>k.time;
        else return leval>k.leval;
    }
}a[100010],b[100010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for(i=0;i<n;i++)rd(a[i].time),rd(a[i].leval);
        for(i=0;i<m;i++)rd(b[i].time),rd(b[i].leval);
        sort(a,a+n);
        sort(b,b+m);
        int cnt=0;
        ll money=0;
        int tmp[103]={0};
        for(i=0,j=0;i<m;i++)
        {
            while(j<n&&a[j].time>=b[i].time)tmp[a[j].leval]++,j++;
            for(int k=b[i].leval;k<=100;k++)
                if(tmp[k])
                {
                    cnt++;
                    tmp[k]--;
                    money+=b[i].time*500+b[i].leval*2;
                    break;
                }
        }
        printf("%d %lld\n",cnt,money);
    }
}
