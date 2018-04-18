

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

const int N=205;
const double eps=1e-8;
double a[N][N];
int equ,var; //equ方程个数,var变量个数,0~var
int gauss()
{
    int r,c; //r当前处理的行,c当前处理的列
    for(r=0,c=0;r<equ&&c<var;r++,c++)
    {
        int mx=r;   //选绝对值最大的那一行,减少误差
        for(int i=r+1;i<equ;i++)
        {
            if(fabs(a[i][c])>fabs(a[mx][c]))
                mx=i;
        }
        if(fabs(a[mx][c])<eps) //如果在第r行之后整列都是0,则该变量为自由变元
        {
            r--;
            continue;
        }
        if(mx!=r)
        {
            for(int i=0;i<=var;i++)
            {
                swap(a[r][i],a[mx][i]);
            }
        }
        for(int i=c+1;i<=var;i++)a[r][i]/=a[r][c];//整列约去系数
        a[r][c]=1.0;//第r行第c列变成1,然后它上面和它下面变成0
        for(int i=0;i<equ;i++)
        {
            if(i==r)continue;
            for(int j=c+1;j<=var;j++)   //要使a[i][c]=0,则需要a[i][c]倍
                a[i][j]-=a[i][c]*a[r][j];
            a[i][c]=0.0;
        }

    }
    for(int i=r;i<equ;i++)if(fabs(a[i][var])<eps)return -1;//无解
    return var-r;   //返回自由变元数
}
int main()
{
    scanf("%d",&equ);
    var=equ;
    for(int i=0;i<equ;i++)
        for(int j=0;j<=var;j++)
            scanf("%lf",&a[i][j]);
    if(gauss()==0)
    {
        for(int j=0;j<equ;j++)
            printf("%.2f\n",a[j][var]);
    }
    else printf("No Solution\n");

}
