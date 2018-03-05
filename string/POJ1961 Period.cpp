


//地址:http://poj.org/problem?id=1961
//题意: 给一个字符串,判断该字符串是否是由一个字符串循环k次得到的(POJ1961 Period)
//解答:对字符串s自匹配求出next数组,根据定义,对于每个i,s[ i – next[i] + 1 ~ i ]与s[1~next[i]]是相等的,并且不存在更大的next值满足这个条件。
		仔细分析nex数组的含义与计算过程,可以发现,当 i-next[i]能整除i时, s[ 1 ~ i-next[i] ]就是s[1~i]的最小循环元,它的最大循环次数就是i/(i-next[i]),
    进一步的,如果i-next[next[i]]能整除i,那么s[1 ~ i-next[ next[i] ]]就是s[1~i]的次小循环元,依次类推,我们可以求出s[1~i]所有可能的循环元
    int nex[1000100];
    char s[1000100];
    int main()
    {
        int n,k=1;
        while(scanf("%d",&n))
        {
            if(!n)break;
            scanf("%s",s+1);
            nex[1]=0;
            for(int i=2,j=0;i<=n;i++)
            {
                while(j>0&&s[i]!=s[j+1])j=nex[j];
                if(s[i]==s[j+1])j++;
                nex[i]=j;
            }
            printf("Test case #%d\n",k++);
            for(int i=2; i<=n;i++)
            {
                if(i%(i-nex[i])==0&&i/(i-nex[i])>1)
                {
                    printf("%d %d\n",i,i/(i-nex[i]));
                }
            }
            printf("\n");
        }
    }
