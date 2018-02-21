

1)	中缀表达式转后缀表达式  O(n)
  a)	建立一个用于存运算符的栈,逐一扫描该中缀表达式中的元素
      i)	如果遇到一个数,则输出该数
      ii)	如果遇到左括号,把左括号入栈
      iii)	如果遇到右括号,不断取出栈顶并输出,直到栈顶为左括号,然后把左括号出栈
      iv)	如果遇到运算符,只要栈顶符号的优先级不低于新符号,就不断取出栈顶并输出,最后把新符号入栈 (优先级 : 乘除>加减>左括号)
  b)	依次取出并输出栈中的所有剩余符号,最终输出的序列就是一个与原中缀表达式等价的后缀表达式
  c)	如果式中数字为多位数,并且表达式是使用字符串逐字符存储的,我们只需要稍加判断,把连续的一段数字看成一个数即可


#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <stack>
#include <stdlib.h>
#include <ctype.h>
#include <queue>
#include <bitset>
#include<cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define E 2.7182818284590452353602874713527
#define bg(x) cout<<x<<"@@@"<<endl
#define lowbit(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
#define pii pair<int,int>
template <typename T>inline void rd(T &x) {
    char c=getchar();int s=1;
    while(c!='-'&&!isdigit(c))c=getchar();
    if(c=='-')s=-1,x=0;else x=c-'0';
    while(c=getchar(),isdigit(c))x=x*10+c-'0';x*=s;
}
template <typename T>inline void wd(T x){
    if(x/10)wd(x/10);putchar(x%10+'0');
}
template <typename T>inline void we(T x){
    if(x<0)x=-x,putchar('-');wd(x);putchar('\n');
}




int main() {
    string s;
    while(cin>>s)
    {
        int i,l=s.size();
        stack<char >q;
        int sum=0;
        for(i=0;i<l;i++)
        {
            if(isdigit(s[i])){
                sum=sum*10+s[i]-'0';
            }
            else
            {
                if(sum!=0)
                {
                    printf("%d ",sum);
                    sum=0;
                }
             if(s[i]=='(')
                q.push(s[i]);
            else if(s[i]==')')
            {
                while(q.top()!='(')
                {
                    printf("%c ",q.top());
                    q.pop();
                }
                q.pop();
            }
            else
            {
                if(s[i]=='*'||s[i]=='/')
                {
                    while(q.size()&&(q.top()=='*'||q.top()=='/'))
                    {
                        printf("%c ",q.top());
                        q.pop();
                    }
                    q.push(s[i]);
                }
                else if(s[i]=='+'||s[i]=='-')
                {

                    while(q.size()&&(q.top()=='+'||q.top()=='-'||q.top()=='*'||q.top()=='/'))
                    {
                        printf("%c ",q.top());
                        q.pop();
                    }
                    q.push(s[i]);
                }

            }}
        }
        if(sum!=0)
            printf("%d ",sum);
        while(q.size())
        {
            printf("%c ",q.top());
            q.pop();
        }
        printf("\n");
    }
}
