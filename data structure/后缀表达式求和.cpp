

1)	后缀表达式求值  O(n)
  a)	建立一个用于存数的栈,逐一扫描该后缀表达式中的元素
    i)	如果遇到一个数,则把该数入栈
    ii)	如果遇到运算符,就取出栈顶的两个数进行计算,把结果入栈
    (注意:先取出来的数作为第二项,即作为减数或除数,因为栈是后进先出)
  b)	扫描完毕后,栈中恰好剩下一个数,就是该后缀表达式的值
  
  
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


int main()
{
    char c;
    stack<int>p;
    int sum=0;
    for(c=getchar();c!='@';c=getchar())
    {
        if(isdigit(c))
        {
            sum=sum*10+c-'0';
        }
        else if(c=='.')
        {
            p.push(sum);
            sum=0;
        }
        else
        {
            int x=p.top();p.pop();
            int y=p.top();p.pop();
            if(c=='+')p.push(x+y);
            else if(c=='-')p.push(y-x);
            else if(c=='*')p.push(x*y);
            else if(c=='/')p.push(y/x);
        }
    }
    we(p.top());
}
