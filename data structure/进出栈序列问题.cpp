

1)	题目:给定1~n这n个数和一个无限大的栈,每个数都要进栈并且出栈一次,如果进栈的顺序为1,2,3,4,…,n 那么可能的出栈顺序有多少种
2)	方法
    a)	方法一:搜索(枚举/递归), O(2n)
       一个很直观的想法是,面对任何一个状态我们只有两种选择
        i)	把下一个数入栈
        ii)	把当前栈顶的数出栈(如果栈非空)
               我们可以枚举每一步如何选择,用递归实现这个规模为O(2n)的枚举,这样就得到了所
            有可能的出栈序列
    b)  方法二:递推  O(n2)     求出栈序列有多少种,并不需要求具体的方案
        i)	设s[n]表示进栈顺序为1,2,3,…,n时可能的出栈序列总数 
        ii)	根据递推的理论,我们需要想办法把问题分解成若干个类似的子问题
        iii)	考虑“1”这个数排在最终出栈序列中的位置,如果最后“1”这个数排在第k个,那么整个序列的出栈过程就是
            (1)	整数1入栈
            (2)	整数2~k这个k-1个数按某种顺序出栈
            (3)	整数1出栈,排在第k个
            (4)	整数k+1~n这n-k个数按照某种顺序出栈
            iv)	于是整个问题就被“1”这个数划分成了“k-1个数进出栈”和“n-k个数进出栈”两个子问题
        v)	递推公式
                                  S[n] = S[k-1]*S[n-k]  k=1,2,...,n
       vi)	代码:
                s[0]=1;s[1]=1;
                  for(int i=2;i<=100;i++)
                  {
                       for(int j=1;j<=i;j++)
                           s[i]+=s[j-1]*s[i-j];
                          }
   c)   方法三:动态规划  O(n2)
      i)	在任何一个时刻,我们实际上只关心有多少个数尚未入栈,有多少个数还在栈里,并做出一步合法的操作,而并不关心这些数具体是哪些
      ii)	因此我们可以用f[ i ][ j ]表示有i个数尚未入栈,目前有j个数在栈里,已经有n-i-j个数出栈时的方案总数
      iii)	在最终状态下,即所有数都已经出栈时,顺序已经确定,所以边界为f[0][0]=1
      iv)	我们需要求出初始状态下,即所有数尚未进栈时,可以到达上述边界的方案总数,所以目标为f[n][0]
      v)	每一步的两种决策分别是“把一个数入栈 ”和“把栈顶的数出栈”,故公式
                          f[ i ][ j ] = f[ i-1 ][ j ] + f[ i ][ j-1 ] ;
   d)   方法四:数学  O(n)
      i)	该问题等价于求第n项的Catalan数
      ii)	代码:
          ll f[10001];
          void a()
          {
              int i;
              ll x,y;
              f[0]=f[1]=1;
              for(i=2;i<10001;i++)
              {
                  f[i]=f[i-1]*(4*i-2)%mod;
                      x=poww(i+1,mod-2,mod);
                  f[i]=(f[i]*((x+mod)%mod))%mod;
              }
          }
