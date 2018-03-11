
//地址:https://www.luogu.org/problemnew/show/P3620
//题意:给你n个数,先求n个数相邻两个数之差,从这个差数组里面取k对数,每个数只能取一次,求k对数最小值
//题解: 如果k=1,答案显然是d数列中的最小值
        如果k=2,答案是以下情况之一:
          (1)选择最小值d[i],以及除了d[i-1],d[i],d[i+1]之外其他数中的最小值
          (2)选择最小值d[i]左右两侧的两个数,即d[i-1]和d[i+1]
        这很容易证明:
          如果d[i-1]和d[i+1]都没有选,那么不选最小值d[i]一定不优,如果d[i-1]和d[i+1]选了一个,那么把选了的那个换成d[i],
          答案也会变小,所以最优解必定是上面两种情况之一
        通过上述证明,我们得出一个推论:在最优解中,最小值左右两侧的数要么同时选,要么都不选
            因此,我们可以先选上d数列中的最小值,然后把d[i-1],d[i],d[i+1]从d数列中删去,把d[i-1]+d[i+1]-d[i]加入到d数列中刚才执行
        删除的位置,最后,求解"从新的d数列中选出不超过k-1个数,使他们的和最小,并且相邻两个数不能同时被选"这个子问题
            在这个子问题中,
                如果选了d[i-1]+d[i+1]-d[i]这个数,相当于去掉d[i],换上d[i-1]和d[i+1],
                如果没选,那么刚才选择最小值d[i]显然是一步最优策略
            综上所述,我们得到了这样一个算法:
              (1)建立一个链表L,连接n-1个结点,结点上分别记录数值d[1],d[2],...,d[n-1],即每两个相邻办公室之间的距离
              (2)建立一个小根堆,与链表构成映射关系,就是说堆中也有n-1个结点,结点权值分别是d[1],d[2],...,d[n-1],并且
                 同时记录对应的链表结点的指针
              
              (3)取出堆顶,把权值累加到答案中,设堆顶对应链表结点的指针为p,数值为L(p),在链表中删除p,p->pre,p->nex,
                 在同样的位置插入一个新结点q,记录数值L(q)=L(p->pre)+L(p->nex)-L(p),在堆中也同时删除对应p->nex和
                 p->pre结点,插入对应链表结点q,权值为L(q)的新结点              
              (4)重复上述操作k次,就得到了最终答案       
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


int a[100100],pre[100100],nex[100100],v[100110],pp,f[100100];
int n,m;
int x=0,ans=0;
void up(int p)
{
    while(p>1)
    {
        if(a[f[p]]<a[f[p>>1]])
        {
            swap(f[p],f[p>>1]);
            swap(v[f[p]],v[f[p>>1]]);
            p/=2;
        }
        else break;
    }
}
void down(int l,int r)
{
    int t=l*2;
    while(t<=r)
    {
        if(t<r&&a[f[t]]>a[f[t+1]])t++;
        if(a[f[t]]<a[f[l]])
        {
            swap(f[t],f[l]);
            swap(v[f[t]],v[f[l]]);
            l=t;t=l*2;
        }
        else break;
    }
}
void ins(int i)
{
    f[++pp]=i;v[i]=pp;
    up(pp);
}
void move(int i)
{
    f[v[i]]=f[pp];v[f[pp]]=v[i];pp--;
    up(v[i]);down(v[i],pp);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)rd(a[i]);
    for(int i=1;i<n;i++){
        a[i]=a[i+1]-a[i];
        pre[i+1]=i;
        nex[i]=i+1;
        ins(i);
    }
    for(int i=1;i<=m;i++)
    {
        x=f[1];ans+=a[x];
        if(pre[x]==0&&nex[x]==n)break;
        else if(pre[x]==0)
        {
            move(x);move(nex[x]);
            pre[nex[nex[x]]]=0;
        }
        else if(nex[x]==n)
        {
            move(x);move(pre[x]);
            nex[pre[pre[x]]]=n;
        }
        else
        {
            move(x);move(pre[x]);move(nex[x]);
            a[x]=a[pre[x]]+a[nex[x]]-a[x];
            ins(x);
            pre[x]=pre[pre[x]];nex[pre[x]]=x;
            nex[x]=nex[nex[x]];pre[nex[x]]=x;
        }
    }
    we(ans);
}
