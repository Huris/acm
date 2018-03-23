


//地址:http://poj.org/problem?id=2279
//题意:给你n个学生,学生编号1~n,排成k行,每行n1,n2,n3...nk个人,每行递减,每列递减,问有几种排法?
//题解:1.dp,设置一个5维的数组,因为在合法的合影方案中每行每列的身高都是单调的,所以我们可以从高到低依次考虑标记为1,2,...,n的
         学生站的位置,这样一来,在任意位置,已经安排好位置的学生在每一行中占据的一定是从左端开始的连续若干个位置,用一个k元组(a1,a2,a3,a4,a5)
         表示每一行已经安排的学生人数,即可描绘出"已经处理的部分"的轮廓
          当安排一名新的学生时,我们考虑所有满足如下条件的行号i:
            1.a[i]<n[i]
            2.i=1或a[i-1]>a[i]
          只要该学生站在这样的一行中,每列学生的身高单调性也就得到满足,换言之,我们不需要关心已经站好的(a1+a2+a3+...+ak)名学生的具体方案,k元
          组(a1,a2,a3...ak)描绘的轮廓内合影方案总数就足以构成一个子问题,因此我们可以把a1,a2,a3...ak作为阶段,当安排一名新的学生时,a1,a2,...,ak
          其中之一会增加1,从而转移到后续的阶段,符合各维度线性增长的形式
            简便起见,我们假设k=5,当k<5时,我们可以增加人数为0的排,使其等价于k=5的问题,动态规划算法如下
            f[a1][a2][a3][a4][a5]表示各排从左端起分别站了a1,a2,a3,a4,a5个人时,合影方案数量
           边界:f[0][0][0][0][0]=1,其余为0
           目标:f[a1][a2][a3][a4][a5]
           转移:若a1<n1,则令f[a1+1][a2][a3][a4][a5]+=f[a1][a2][a3][a4][a5],若a2<n2且a1>a2,则令f[a1][a2-1][a3][a4][a5]+=f[a1][a2][a3][a4][a5]
           第3~5排同理
           
           不过该题如果使用dp做法会超内存
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
            #define inf 0x3f3f3f3f

            const int N=3e5+7;


            int a[31][31][31][31][31];

            int main()
            {
                int n;
                while(scanf("%d",&n))
                {
                    if(!n)break;
                    memset(a,0,sizeof(a));
                    a[0][0][0][0][0]=1;
                    int b[6]={0};
                    for(int i=1;i<=n;i++)
                        scanf("%d",b+i);
                    for(int q=1;q<=b[1];q++)
                        for(int w=0;w<=b[2]&&w<=q;w++)
                            for(int e=0;e<=b[3]&&e<=w;e++)
                                for(int r=0;r<=b[4]&&r<=e;r++)
                                    for(int t=0;t<=b[5]&&t<=r;t++)
                                    {
                                        a[q][w][e][r][t]+=a[q-1][w][e][r][t];
                                        if(w>0)a[q][w][e][r][t]+=a[q][w-1][e][r][t];
                                        if(e>0)a[q][w][e][r][t]+=a[q][w][e-1][r][t];
                                        if(r>0)a[q][w][e][r][t]+=a[q][w][e][r-1][t];
                                        if(t>0)a[q][w][e][r][t]+=a[q][w][e][r][t-1];
                                    }
                    printf("%d\n",a[b[1]][b[2]][b[3]][b[4]][b[5]]);
                }
            }
            
            
      2.数学方法(杨氏三角+钩子公式)
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
        #define inf 0x3f3f3f3f
        #define ll long long


        const int N=3e5+7;

        ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

        ll d[40],hock[40];
        int main()
        {
            ll n;
            while(scanf("%lld",&n))
            {
                if(!n)break;
                for(int i=1;i<=n;i++)scanf("%lld",d+i);
                ll tot=0;
                memset(hock,0,sizeof(hock));
                for(int i=1;i<=n;i++)   //遍历每一行
                    for(int j=1;j<=d[i];j++) //该行的遍历每一列
                    {
                        tot++;
                        for(int k=i+1;k<=n;k++) //遍历该列上面的每一行
                        {
                            if(d[k]>=j)hock[tot]++; //如果该列上面有空格,则hock加1
                            else break;
                        }
                        hock[tot]+=d[i]-j+1;  //最后加上该行该列右边的数字和自己
                    }
                ll s1=1,s2=1;
                for(int i=1;i<=tot;i++)
                {
                    s1*=i;
                    s2*=hock[i];
                    ll s=gcd(s1,s2);
                    s1/=s;
                    s2/=s;
                }
                printf("%lld\n",s1/s2);
            }
        }
      
      
      
      
      
      
