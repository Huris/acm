
阶乘分解
1)	给定整数n(1<=n<=1e6),试把阶乘n!分解质因数,按照算数基本定理的形式输出分解结果中的p[i]和c[i]即可
2)	题解
  a)	n!的每个质因子都不会超过n,我们可以先筛1~n的每个质数p,然后考虑阶乘n!中一共包含多少个质因子p
  b)	n!中质因子p的个数就是1~n中每个数包含质因子p的数目之和,在1~n中,p的倍数,即至少包含1个质因子p的显然有n/p个,
      而p2的倍数,即至少包含2个质因子p的有n/p2个,不过其中的1个质因子已经在n/p里统计了,所以只需要再统计第2个质因子,即累加上n/p2
  c)	对于每个p,只需要O(logn)的时间计算上述和式,故对整个n!分解质因数的时间复杂度为O(nlogn)
  d)	代码
      #include <stdio.h>
      #include <string>
      #include <string.h>
      #include <iostream>
      #include <math.h>
      #include <algorithm>
      #include <vector>
      #include <queue>
      using namespace std;
      #define inf 0x3f3f3f3f
      #define ll long long
  
      const int N=1000006;
      int prime[1000040];
      int p[N];   //质因子
      int c[N];   //质因子个数
      void init()
      {
          for(int i=2;i<=N;i++)
          {
              if(!prime[i])prime[++prime[0]]=i;
              for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++)
              {
                  prime[prime[j]*i]=1;
                  if(i%prime[j]==0)break;
              }
          }
      }
      int main()
      {
          init(); //初始化得到prime数组
          int n,i,cnt=0,nn;
          scanf("%d",&n);
          for(i=1;prime[i]<=n;i++)
          {
              p[++cnt]=prime[i];
              nn=n;
              while(nn/prime[i])
              {
                  c[cnt]+=nn/prime[i];//每次加上nn/prime的个数
                  nn/=prime[i];
              }
          }
          for(int i=1;i<=cnt;i++)
              printf("%d %d\n",p[i],c[i]);
      }
