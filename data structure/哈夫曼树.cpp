

哈夫曼树(最优二叉树)
  1)	问题:给出一棵包含n个叶子结点的k叉树,其中第i个叶子结点带有权值w[i],
      求 其中l[i]表示第i个叶子结点到根结点的距离,该问题也被称为k叉哈夫曼树问题
  2)	为了最小化,应该让权值大的叶子结点的深度尽量小,当k=2时,我们很容易想到用下面这个贪心算法来求出二叉哈夫曼树
    a)	建立一个小根堆,插入这n个叶子结点的权值
    b)	从堆中取出最小的两个权值w1和w2,令ans+=w1+w2
    c)	建立一个权值为w1+w2的树结点p,令p成为权值为w1和w2的树结点的父亲
    d)	在堆中插入权值w1+w2
    e)	重复第b~d步直至堆的大小为1
  3)	最后,由所有新建的p与原来的叶子结点构成的树就是哈夫曼树,变量ans就是的最小值
  4)	对于k(k>2)叉哈夫曼树的求解,直观的想法是在上述贪心算法的基础上,改为每次从堆中取出最小的k个权值,
      然而,仔细思考可以发现,如果在执行最后一轮循环时,堆的大小在2~k-1之间(不足以取出k个),
      那么整个哈夫曼树的根的子节点个数就小于k,这显然不是最优解我们任取哈夫曼树中的一个深度最大的结点,把它改为树根的子节点,就会使变小。
  5)	因此,我们应该在执行上述贪心算法之前,补加一些额外的权值为0的结点,使叶子结点的个数n满足(n-1)%(k-1)=0,
      也就是说,我们让子节点不足k个的情况发生在最底层,而不是根结点处,
      在(n-1)%(k-1)=0时,执行“每次从堆中取出最小的k个权值”的贪心算法就是正确的。
      (每次让k个结点变为1个,即每次减少k-1个结点,然后,最后剩下一个不用计算,故需要满足公式 (n-1)%(k-1)=0 )
  6)	代码:
      int main()
      {
          int n;
          scanf("%d",&n);
          priority_queue<int,vector<int>,greater<int> >p;
          for(int i=0;i<n;i++){
              int x;
              rd(x);
              p.push(x);
          }
          ll ans=0;
          ll x;
          while(p.size()>1)
          {
              x=0;
              x+=p.top();p.pop();
              x+=p.top();p.pop();
              ans+=x;
              p.push(x);
          }
          we(ans);
      }
  7)	双队列法构造哈夫曼树O(nlogn)
    a)	定义两个双端队列a,b
    b)	先把所有数都保存在一个队列a中
    c)	将队列a元素排序
    d)	定义单次求和sum,=0和总的和ans=0
    e)	然后分别比较k次a.front(),b.front(),sum加上小的那个数,然后pop掉
    f)	k次和sum插入b中,此时b为单调递增,无需排序
    g)	ans+=sum , 将sum插入到b中
    h)	代码:
        deque<ll>a,b;
        int main()
        {
            int n;
            rd(n);
            ll x;
            for(int i=0;i<n;i++)
            {
                rd(x);
                a.push_back(x);
            }
            sort(a.begin(),a.end());
            ll ans=0;
            while(b.size()+a.size()>1)
            {
                ll sum=0;
                for(int i=0;i<2;i++)
                {
                    if(a.empty())sum+=b.front(),b.pop_front();
                    else if(b.empty())sum+=a.front(),a.pop_front();
                    else if(a.front()<b.front())sum+=a.front(),a.pop_front();
                    else sum+=b.front(),b.pop_front();
                }
                ans+=sum;
                b.push_back(sum);
            }
            we(ans);
        }
