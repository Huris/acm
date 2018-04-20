

//地址:http://www.nbuoj.com/v8.8/Problems/Problem.php?pid=2382
//题意:给你n个数,每个数表示前面有几个人比自己高,求原数组
//题解:如果最后一个数前面有a[i]个人比他高,则a[i]的排名应该是a[i]+1;
       如果倒数第二个人前面有a[i-1]个人比他高,则
        1.如果a[i-1]<a[i],则他的身高为a[i-1]+1
        2.如果a[i-1]>=a[i],则他的身高为a[i-1]+2
       依次类推,如果第k个人前面有a[k]个人比他高,那么他的身高是数值1~n中第a[k]+1小的没有出现过的数
       具体来说,我们建立一个长度为n的01序列b,起初全部为1,然后,从n到1倒序扫描每个a[i],对每个a[i]执行以下两个操作
       1.查询序列b中第a[i]+1个1在什么位置,这个位置号就是第i个人的身高
       2.把b[i]减1
       也就是说我们要维护一个01序列,支持查询第k个1的位置(k为任意整数),以及修改序列中的一个数值
       做法1.树状数组+二分 O(nlogn)
       做法2.树状数组+倍增
       
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


const int N=1e5+7;
int vis[N];
int a[N],c[N],b[N];
int n;
void ins(int x,int y){for(;x<=n;x+=x&-x)c[x]+=y;}
int sum(int x){int s=0;for(;x;x-=x&-x)s+=c[x];return s;}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(0));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ins(i,1);
        }
        for(int i=n;i>=1;i--)
        {
            int l=1,r=n;
            int mid;
            while(l<r)
            {
                int mid=l+r>>1;
                if(sum(mid)>=a[i]+1)r=mid;
                else l=mid+1;
            }
//            printf("%d !!!\n",l);
            b[l]=i;
            ins(l,-1);
        }
        int i;
        for(i=1;i<=n;i++)
            if(b[i]==1)
                break;
        printf("%d\n",i);
//        for(int i=1;i<=n;i++)
//            printf("%d ",b[i]);
//        printf("\n");
    }
}
