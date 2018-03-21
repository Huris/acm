

//地址:http://poj.org/problem?id=1733
//题意:给你m个区间的奇偶性,判断哪个区间奇偶性第一次出现矛盾
//题解:  如果我们用sum数组表示序列s的前缀和,那么在每个回答中:
          1.s[l~r]有偶数个1,等价于sum[l-1]与sum[r]奇偶性相同
          2.s[l~r]有奇数个1,等价于sum[l-1]与sum[r]奇偶性不同
         注意,这里没有求出sum数组, 我们只是把sum看做变量,此时
          1.若x1与x2奇偶性相同,x2与x3奇偶性也相同,那么x1与x3奇偶性也相同
          2.若x1与x2奇偶性相同,x2与x3奇偶性不同,那么x1与x3奇偶性不同
          3.若x1与x2奇偶性不同,x2与x3奇偶性不同,那么x1与x3奇偶性相同
         另外,序列长度N很大,但问题数M较少,可以先离散化方法把每个问题的两个整数l-1和r缩小到等价的1~2m以内的范围
         
         
        第一种方法:使用"带边权"的并查集
          边权d[x]为0,表示x与fa[x]奇偶性相同,为1,表示x与fa[x]奇偶性不同
          在路径压缩上,对x到树根路径上的所有边权做异或运算,即可得到x与树根的奇偶性关系
          对于每个问题,设在离散化之后l-1和r的值分别是x,y,设ans表示该问题的回答(0代表偶数个,1代表奇数个)
          1.先检查x和y是否在同一个集合内(奇偶关系是否已知),fi(x),fi(y)都执行完成后,d[x]^d[y]即为x和y的奇偶性关系,若d[x]^d[y]!=ans,说明小A在撒谎
          2.若x和y不在同一个集合内,则合并两个集合,此时应该先通过fi操作得到两个集合的树根(设为p和q),令p为q的子节点,已知d[x]与d[y]分别表示路径x~p和
            y~q之间所有边权的"XOR"和,p~q之间的边权d[p]是待求的值,显然,路径x~y由路径x~p,p~q,q~y组成,因此x与y的奇偶性关系ans=d[x]^d[p]^d[y]
            进而推出新连接的边权 d[p]=d[x]^d[y]^ans;
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
            struct node
            {
                int l,r,s;
            }e[N];
            int n,m;
            int tmp[N];
            int fa[N];
            int d[N];

            int fi(int x)
            {
                if(x==fa[x])return x;
                int r=fi(fa[x]);
                d[x]^=d[fa[x]];
                return fa[x]=r;
            }
            int main()
            {
                char s[5];
                scanf("%d%d",&n,&m);
                int cnt=0;
                for(int i=1;i<=N;i++)fa[i]=i;
                for(int i=1;i<=m;i++)
                {
                    scanf("%d%d%s",&e[i].l,&e[i].r,s);
                    if(s[0]=='o')e[i].s=1;
                    else e[i].s=0;
                    tmp[cnt++]=e[i].l-1;
                    tmp[cnt++]=e[i].r;
                }
                sort(tmp,tmp+cnt);
                n=unique(tmp,tmp+cnt)-tmp;
                for(int i=1;i<=m;i++)
                {
                    int x=lower_bound(tmp,tmp+n,e[i].l-1)-tmp;
                    int y=lower_bound(tmp,tmp+n,e[i].r)-tmp;
                    int p=fi(x),q=fi(y);
                    if(p==q)
                    {
                        if((d[x]^d[y])!=e[i].s)
                        {
                            printf("%d\n",i-1);
                            return 0;
                        }
                    }
                    else
                    {
                        fa[p]=q;
                        d[p]=d[x]^d[y]^e[i].s;
                    }
                }
                printf("%d\n",m);
            }
            
        第二种方法:使用"扩展域"的并查集
             把每个变量x拆成两个节点x_odd和x_even,其中x_odd表示sum[x]是奇数,x_even表示sum[y]是偶数
             我们也常把这两个节点称为x的"奇数域"和"偶数域"
             对于每个问题,设在离散化后l-1和r的值分别是x和y,设ans表示该问题的回答(0代表偶数个,1代表奇数个)
               1.若ans=0,则合并x_odd与y_odd,x_even和y_even,这表示"x为奇数"与"y为奇数"可以推出,"x为偶数"与"y为偶数"可以推出,他们是等价的信息
               2.若ans=1,则合并x_odd与y_even,x_even和y_odd,这表示"x为奇数"与"y为偶数"可以推出,"x为偶数"与"y为奇数"可以推出,他们是等价的信息
              上述合并的同时还维护了关系的传递性,试想,在处理完(x,y,0)和(y,z,1)两个回答之后,x和z之间的关系也就已知了,这种做法相当于在无向图上维护
            结点之间的连通情况,只是扩展了多个域来对应多种传递关系
              在处理每个问题之前,我们需要检查是否存在矛盾,
              1.若两个变量x和y对应的x_odd和y_odd结点在同一个集合内,则已知二者奇偶性相同
              2.若两个变量x和y对应的x_odd和y_even结点在同一个集合内,则已知二者奇偶性不同
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

struct node
{
    int l,r,s;
}e[N];
int n,m;
int tmp[N],d[N],fa[N];
int fi(int x)
{
    if(x==fa[x])return x;
    return fa[x]=fi(fa[x]);
}
int main()
{
    char s[5];
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%s",&e[i].l,&e[i].r,s);
        if(s[0]=='e')e[i].s=0;
        else e[i].s=1;
        tmp[++cnt]=e[i].l-1;
        tmp[++cnt]=e[i].r;
    }
    sort(tmp+1,tmp+cnt+1);
    n=unique(tmp+1,tmp+cnt+1)-tmp-1;
    for(int i=0;i<=n*2;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x_odd=lower_bound(tmp+1,tmp+1+n,e[i].l-1)-tmp-1;
        int x_even=x_odd+n;
        int y_odd=lower_bound(tmp+1,tmp+1+n,e[i].r)-tmp-1;
        int y_even=y_odd+n;
        if(e[i].s==0)
        {
            if(fi(x_odd)==fi(y_even))
            {
                printf("%d\n",i-1);
                return 0;
            }
            fa[fi(x_odd)]=fi(y_odd);
            fa[fi(x_even)]=fi(y_even);
        }
        else
        {
            if(fi(x_odd)==fi(y_odd))
            {
                printf("%d\n",i-1);
                return 0;
            }
            fa[fi(x_odd)]=fi(y_even);
            fa[fi(x_even)]=fi(y_odd);

        }
    }
    printf("%d\n",m);
}
             
             
             
             
             
             
             
