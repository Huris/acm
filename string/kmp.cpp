
kmp算法
    1)	kmp算法,又称模式匹配算法,能够在线性时间内判定字符串a[1~n]是否为字符串b[1~m]的子串,并求出字符串a在字符串b中各次出现的位置
    2)	O(nm)暴力做法
        尝试枚举字符串b中的每个位置i,把字符串a与字符串b的后缀b[i~m]对齐,向后扫描逐一比较a[1]与b[i],a[2]与b[i+1]……是否相等
    3)	O(n+m)字符串hash
         可以在O(n)的时间内预处理一个字符串的所有前缀hash值,并在O(1)的时间内查询该字符串任意一个子串的hash值,
         所以,一个很直接的想法就是:枚举字符串b中每一个位置i(n<=i<=m),检查字符串a的hash值与字符串b的子串b[i-n+1~i]的hash值是否相同,
         即可得到该问题的解
    4)	O(n+m)kmp
      a)	算法过程
        i)	对字符串a进行自我匹配,求出nex数组,其中nex[i]表示“a中以i结尾的非前缀子串”与“a的前缀”能够匹配的最长长度,即
                  nex[ i ]=max{ j } , 其中 j < i 并且a[ i – j +1 ~ i ] = a [ 1 ~ j ]
        ii)	对字符串a和b进行匹配,求出一个数组f,其中f[i]表示“b中以i结尾的子串”与“a的前缀”能够匹配的最大长度,即
                  f [ i ] = max{ j } ,其中j <= i 并且b[ i – j +1 ~ i ] = a [ 1 ~ j ]
      b)	kmp算法nex数组和f数组求法
        i)	初始化nex[1]=j=0,假设nex[1~i-1]已求出,下面求nex[i]
        ii)	不断尝试扩展匹配长度j,如果扩展失败(下一个字符不相等),令j=nex[ j ],直至j为0 (应该重新从头开始匹配)
        iii)	如果能够扩展成功,匹配长度j就增加1,nex[ i ]的值就是j
        iv)	f数组与nex数组求法基本一致
      c)	代码
            int nex[10010];
      int f[100100];
      int main()
      {
          string s,t;
          cin>>s>>t;
          int l1=s.size(),l2=t.size();
          int cnt=0;
          nex[0]=f[0]=-1;
          for(int i=1,j=-1;i<l1;i++)
          {
              while(~j&&s[i]!=s[j+1])j=nex[j];
              if(s[i]==s[j+1])j++;
              nex[i]=j;
          }
          for(int i=1,j=-1;i<l2;i++)
          {
              while(~j&&(j==l1-1||t[i]!=s[j+1]))j=nex[j];
              if(t[i]==s[j+1])j++;
              f[i]=j;
              if(f[i]==l1-1){
                  cnt++;
              }// 匹配成功,此时t[i]=s[l1-1]
          }
          we(cnt);
      }
