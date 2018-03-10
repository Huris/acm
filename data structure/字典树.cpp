 trie字典树(一种用于实现字符串快速检索的多叉树结构)
    1)	初始化
        一棵空trie仅包含一个根结点,该点的字符指针均指向空
    2)	插入
        当需要插入一个字符串s时,我们令一个指针p起初指向根结点,然后,依次扫描s中的每个字符c
          a)	若p的c字符指针指向一个已经存在的结点q,则令p=q;
          b)	若p的c字符指针指向空,则新建一个结点q,令p的c字符指针指向q,然后令p=q;
          c)	当s中的字符扫描完毕后,在当前结点p上标记它是一个字符串的末尾
    3)	查询
        当需要查询一个字符串s在trie中是否存在时,我们令一个指针p起初指向根结点,然后依次扫描s中的每个字符c
          a)	若p的c字符指针指向空,则说明s没有被插入过trie,结束检索
          b)	若p的c字符指针指向一个已经存在的结点q,则令p=q
          c)	当s中的字符扫描完毕时,若当前结点p被标记为一个字符串的末尾,则说明s在trie中存在,否则说明s没有被插入过trie
    4)  代码
        int trie[100030][26],tot=1;
        int ed[100010];
        void insert(char s[])
        {
            int l=strlen(s),p=1;
            for(int k=0;k<l;k++)
            {
                int ch=s[k]-'a';
                if(trie[p][ch]==0)trie[p][ch]=++tot;
                p=trie[p][ch];
            }
            ed[p]=1;
        }
        int query(char s[])
        {
            int l=strlen(s),p=1;
            for(int k=0;k<l;k++)
            {
                p=trie[p][s[k]-'a'];
                if(p==0)return false;
            }
            return ed[p];
        }
    5)  应用
      n个数,选两个数异或,求异或最大值
        解法:
        1)	我们可以把每个整数看做长度为32的二进制01串(数值较小时在前边补0),并且把a[1]~a[i-1]对应的32位二进制串插入一棵trie树(最低二进制位为叶子结点)
        2)	接下来,对于a[i]对应的32位二进制串,我们在trie中进行一次与查询类似的过程,每一步都尝试沿着“与a[i]的当前位相反的字符指针”向下访问
        3)	若“与a[i]的当前位相反的字符指针”指向空结点,则只好访问与a[i]当前位相同的字符指针,根据异或运算“相同得0,不同得1”,该方法可以找出与a[i]做异或运算结果最大的a[j](其中j<i)
        4)	综上所述,我们循环i=1~n,对于每个i,trie树应该存储了a[1]~a[i-1]对应的32位二进制串,实际上每次i增长前,把a[i]插入trie即可,根据我们刚才提到的“尽量走相反的字符指针”的检索策略,就可以找到所求的a[j],更新答案
        5)	
            const int N=100010;
            int a[N],tot,ans;
            int trie[N*32][2];
            int val[N*32];
            void ins(int x,int y,int tmp)
            {
                if(y<0){val[x]=tmp;return;}
                int z=tmp>>y&1;
                if(!trie[x][z])trie[x][z]=++tot;
                ins(trie[x][z],y-1,tmp);
            }
            int get(int x,int y,int tmp)
            {
                if(y<0)return val[x];
                int z=tmp>>y&1;
                if(trie[x][z^1])return get(trie[x][z^1],y-1,tmp);
                return get(trie[x][z],y-1,tmp);
            }
            int main()
            {
                int n;
                rd(n);
                for(int i=0;i<n;i++)rd(a[i]);
                memset(trie,0,sizeof(trie));
                tot=1;ans=0;
                ins(1,30,a[0]);
                for(int i=1;i<n;i++)
                {
                    ans=max(ans,a[i]^get(1,30,a[i]));
                    ins(1,30,a[i]);
                }
                we(ans);
            }
