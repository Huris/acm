

对顶栈(跟对顶堆类似   处理光标移动查询问题)  HDU4699 Editor
1)	题目类型
插入,删除,左移,右移,查询操作都发生在光标位置处,并且操作完成后,光标最多移动1个位置
2)	算法
   建立两个栈,栈A存储从序列开头到当前光标位置的这一段子序列(包含当前光标),栈B存储从当前光标位置到序列结尾的这一段子序列,二者都以光标所在的那一段作为栈顶,这两个栈合起来就保存了整个序列.
3)	代码
int f[1000100];     //f[i]表示最大前缀和
int sum[1000100];   //sum[i]表示前缀和
int main()
{
    ios::sync_with_stdio(0);
    int n;
    while(cin>>n)
    {
        stack<int>p,q;
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        f[0]=-inf;  //f[0]初始化为负无穷!!!
        char c;int x;
        while(n--)
        {
            cin>>c;
            if(c=='I')  //光标位置插入的话,直接插到左边的栈,并维护最大前缀和
            {
                cin>>x;
                p.push(x);
                sum[p.size()]=sum[p.size()-1]+x;
                f[p.size()]=max(f[p.size()-1],sum[p.size()]);
            }
            else if(c=='L')//左移的话先判光标左边是否为空,不为空的话,移动左边栈顶元素到右边
            {
                if(p.empty())continue;
                q.push(p.top());p.pop();
            }
            else if(c=='R')//右移的话,跟插入差不多
            {
                if(q.empty())continue;  //先判右栈是否为空
                x=q.top();q.pop();
                p.push(x);
                sum[p.size()]=sum[p.size()-1]+x;
                f[p.size()]=max(f[p.size()-1],sum[p.size()]);
            }
            else if(c=='D') //删除,直接删除左栈即可
            {
                p.pop();
            }
            else        //查询直接输出f[x]
            {
                cin>>x;
                cout<<f[x]<<endl;
            }
        }
    }
}
