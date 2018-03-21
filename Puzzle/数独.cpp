


数独(POJ2676/3074)
  1)	数独问题的搜索框架非常简单,我们关心的“状态”就是数独的每个位置上填了什么数
  2)	在每个状态下,我们找出一个还没有填的位置,检查有哪些合法的数字可以填,这些合法的数字就构成该状态向下继续递归的“分支”
  3)	搜索边界
    a)	所有位置都被填满,找到一个解
    b)	发现某个位置没有能填的合法数字,说明当前分支搜索失败,回溯回去
  4)	注意:在任意一个状态下,我们只需要找出1个位置,考虑该位置上填什么数,不需要枚举所有的位置和可填的数字向下递归(因为其他位置在更深的层次会被搜索到)
  5)	策略:在每个状态下,从所有未填的位置里选择“能填的合法数字”最少的位置,考虑该位置上填什么数,作为搜索的分支,而不是任意找出1个位置
  6)	在搜索程序中,影响时间效率的因素除了搜索树的规模(影响算法的时间复杂度),还有在每个状态上记录,检索,更新的开销(影响程序运行的“常数”时间),我们可以使用位运算来代替数组执行“对数独各个位置所填的数的记录”以及“可填性的检查与统计” 这就是我们所说的程序“常数优化”,具体做法
    a)	对于每行每列每个九宫格,分别用一个9位二进制数(全局整数变量)保存哪些数字还可以填
    b)	对于每个位置,把它所在的行,列,九宫格的3个二进制数做位与(&)运算,就可以得到该位置能填哪些数,用lowbit运算就可以把能填的数字取出
    c)	当一个位置填上某个数字之后,把该位置所在的行,列,九宫格记录的二进制数的对应改为0,即可更新当前状态,回溯时改回1即可还原现场
  7)	
    #include <stdio.h>
    #include <algorithm>
    #include <iostream>
    using namespace std;
    string s[10];
    int row[10],col[10],gri[10],cnt[1<<10],num[1<<10],tot;
    int belong[10][10]={
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
    };
    inline void ins(int x,int y,int z)
    {
        row[x]^=1<<z;
        col[y]^=1<<z;
        gri[belong[x][y]]^=1<<z;
    }
    inline int dfs(int now)
    {
        if(now==0)return 1;
        int tmp=10,x,y;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(s[i][j]!='0')continue;
                int val=row[i]&col[j]&gri[belong[i][j]];
                if(!val)return 0;
                if(cnt[val]<tmp)
                {
                    tmp=cnt[val];
                    x=i;y=j;
                }
            }
        }
        int val=row[x]&col[y]&gri[belong[x][y]];
        for(;val;val-=val&-val)
        {
            int z=num[val&-val];
            s[x][y]='1'+z;
            ins(x,y,z);
            if(dfs(now-1))return 1;
            ins(x,y,z);
            s[x][y]='0';
        }
        return 0;
    }

    int main()
    {
        for (int i = 0; i < 1 << 9; i++)
            for (int j = i; j; j -= j&-j) cnt[i]++;
        for (int i = 0; i < 9; i++)
            num[1 << i] = i;
        int t;
        scanf("%d",&t);
        while (t--)
        {
            for (int i = 0; i < 9; i++)
                row[i] = col[i] = gri[i] = (1 << 9) - 1;
            tot=0;
            for(int i=0;i<9;i++)cin>>s[i];
            for(int i=0;i<9;i++)
                for(int j=0;j<9;j++)
                    if(s[i][j]!='0')ins(i,j,s[i][j]-'1');
                    else tot++;
            dfs(tot);
            for(int i=0;i<9;i++)
                cout<<s[i]<<endl;
        }
    }
