

//地址:https://www.luogu.org/problemnew/show/P4035#sub
//题意:有一个球形空间产生器能够在n维空间中产生一个坚硬的球体。现在，你被困在了这个n维球体中，
       你只知道球面上n+1个点的坐标，你需要以最快的速度确定这个n维球体的球心坐标，以便于摧毁这个球形空间产生器。
//题解:高斯消元模板题

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



double a[20][20],b[20],c[20][20];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    //c:系数矩阵,b:常数,二者一起构成增广矩阵
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            c[i][j]=2*(a[i][j]-a[i+1][j]);
            b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
        }
    //高斯消元
    for(int i=1;i<=n;i++)
    {
        //找到x[i]的系数不为0的一个方程
        for(int j=i;j<=n;j++)
        {
            if(fabs(c[j][i])>1e-8)
            {
                for(int k=1;k<=n;k++)swap(c[i][k],c[j][k]);
                swap(b[i],b[j]);
//                break;
            }
        }
        //消去其他方程的x[i]的系数
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            double r=c[j][i]/c[i][i];
            for(int k=i;k<=n;k++)c[j][k]-=c[i][k]*r;
            b[j]-=b[i]*r;
        }
    }
    for(int i=1;i<n;i++)printf("%.3f ",b[i]/c[i][i]);
    printf("%.3f\n",b[n]/c[n][n]);
}
