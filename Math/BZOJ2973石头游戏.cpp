

//地址:https://begin.lydsy.com/JudgeOnline/problem.php?id=4798
//题意:石头游戏在一个n行m列的网格上进行,每个格子对应一种操作序列,操作序列最多有10种,分别用0~9这10个数字表示
       操作序列是一个长度不超过6且循环执行,每秒执行一个字符的字符串,每秒钟,所有格子同时执行各自操作序列里的下一个字符,
       序列中的每个字符是以下格式之一:
       1.数字0~9:表示拿0~9个石头到该格子
       2.NWSE:表示把这个格子内所有的石头推到相邻的格子,N表示上方,W表示左方,S表示下方,E表示右方
       3.D:表示拿走这个格子的所有石头
       给定每种操作序列对应的字符串,以及网格中每个格子对应的操作序列,求石头游戏进行了t秒后,石头最多的格子里有多少个石头,在游戏开始时,网格是空的
//题解:1.设pos(i,j)=(i-1)*m+j
       2.把网格看做长度为n*m的一维向量,定义1行n*m+1列的"状态矩阵"F,下标为0~n*m,其中F[pos(i,j)]记录格子(i,j)中石头的个数
       3.特别的,令F[0]等于1
       4.F会随着时间的增长而不断变化,设Fk表示k秒之后的"状态矩阵",在游戏开始时,根据题意和F的定义,有F0=[1,0,0,0,0,0...]
       5.注意到操作序列的长度不超过6,而1~6的最小公倍数是60,所以每经过60秒,所有操作序列都会重新处于最开始的字符处,
         我们可以统计出第k秒(1<=k<=60),各个格子执行了什么字符,第k+60秒执行的字符与第k秒一定是相同的
       6.对于1~60之间的每个k,各个格子在第k秒执行的操作字符可以构成一个转移矩阵a[k],矩阵行列下标都是0~n*m
       7.构造方法:
         1.若网格(i,j)第k秒的操作字符为"N",且i>1,则令ak[pos(i,j),pos(i-1,j)]=1,表示把石头推到上边的格子,字符WSE类似
         2.若网格(i,j)第k秒的操作字符是一个数字x,则令ak[0,pos(i,j)]=x;
         3.令ak[0,0]=1;
         4.ak的其他部分赋值为0
       8.上述构造实际上是把"状态矩阵"的第0列作为石头来源,ak[0,0]=1保证了F[0]始终为1,ak[0,pos(i,j)]=x相当于从石头来源获取x个石头,放到格子(i,j)中,
          使用矩阵乘法加速递推,遇到常数项时,经常需要在"状态矩阵"中添加一个额外的位置,始终储存常数1,并乘上"状态矩阵"中适当的系数,累加到"状态矩阵"的其他
          位置
       9.设A=πA[i],t=q*60+r(0<=r<60)
            F[t]=F[0]*A^q*πA[i]
       10.使用矩阵乘法和快速幂计算该式,F[t]第1~n*m列中最大值即为所求
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


struct mat
{
    ll a[100][100];
};
int n,m,t,act;
string a[20],b[20];
mat x,ans,f[100];
mat operator *(mat a,mat b)
{
    mat c;
    memset(c.a,0,sizeof(c.a));
    for(int i=0;i<=n*m;i++)
    {
        for(int j=0;j<=n*m;j++)
        {
            for(int k=0;k<=n*m;k++)
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
        }
    }
    return c;
}
void poww(int b)
{
    while(b)
    {
        if(b&1)ans=ans*x;
        x=x*x;
        b>>=1;
    }
}
int main()
{

    scanf("%d%d%d%d",&n,&m,&t,&act);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<act;i++)cin>>b[i];
    for(int i=0;i<=n*m;i++)x.a[i][i]=1;
    ans.a[0][0]=1;
    for(int l=0;l<60;l++)
    {
        f[l].a[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int k=a[i][j-1]-'0';
                char ch=b[k][l%b[k].size()];
                if(ch>='0'&&ch<='9')  f[l].a[pos(i,j)][pos(i,j)]=1,f[l].a[0][pos(i,j)]=ch-'0';
                if(ch=='N'&&i>1) f[l].a[pos(i,j)][pos(i-1,j)]=1;
                if(ch=='W'&&j>1) f[l].a[pos(i,j)][pos(i,j-1)]=1;
                if(ch=='S'&&i<n) f[l].a[pos(i,j)][pos(i+1,j)]=1;
                if(ch=='E'&&j<m) f[l].a[pos(i,j)][pos(i,j+1)]=1;
            }
        }
        x=x*f[l];
    }
    poww(t/60);
    for(int i=0;i<t%60;i++)ans=ans*f[i];
    ll mx=-1;
    for(int i=1;i<=n*m;i++)mx=max(mx,ans.a[0][i]);
    printf("%lld\n",mx);
}
