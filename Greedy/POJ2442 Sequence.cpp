

//地址:http://poj.org/problem?id=2442
//题意:给你m个序列,每个序列有n个数,每次在每个序列中取1个数,求最小的n个和
//题解:先考虑m=2的简化问题,首先对两个序列排序,然后最小的和应该是a[0]+b[0],
       然后第二小的和应该是 a[1]+b[0],a[0]+b[1]中选择一个
       假如第二小的和是a[1]+b[0],则第三小的和应该是 a[1]+b[1],a[2]+b[0],a[0]+b[1]中的最小值
       也就是说,当a[i]+b[j]为当前最小和时,把a[i+1]+b[j]和a[i]+b[j+1]放到优先队列中
       有一种特殊情况,a[0]+b[1]和a[1]+b[0]都会加入a[1]+b[1],产生重复解
       故,我们每次加入优先队列时都要有一个last标记,
          当last为0时,加入a[i+1]+b[j]和a[i]+b[j+1]
          当last为1时,只加入a[i]+b[j+1]
       最后重复m-1次上述算法即可,算法复杂度O(nmlogn)
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


int a[2222];
int b[2002],k;
int c[2002];
struct node
{
    int i,j,last,val;
    node(int ii,int jj,int va,int la){i=ii;j=jj;val=va;last=la;}
    bool operator<(const node & k)const {
        return val>k.val;
    }
};
int main()
{
    int t;
    rd(t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        for(int j=0;j<n;j++)
            rd(a[j]);
        sort(a,a+n);
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n;j++)rd(b[j]);
            sort(b,b+n);
            priority_queue<node>p;
            int u=0;
            p.push(node(0,0,a[0]+b[0],0));
            while(u<n)
            {
                node now=p.top();p.pop();
                c[u++]=now.val;
                if(u==n)break;
                p.push(node(now.i,now.j+1,a[now.i]+b[now.j+1],1));
                if(now.last==0)p.push(node(now.i+1,now.j,a[now.i+1]+b[now.j],0));
            }
            for(int z=0;z<n;z++)a[z]=c[z];
        }
        for(k=0;k<n-1;k++)printf("%d ",a[k]);
        we(a[k]);
    }
}
          
