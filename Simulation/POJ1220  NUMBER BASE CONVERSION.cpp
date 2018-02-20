

//地址:http://poj.org/problem?id=1220
//题意: 给定a进制的一个数,求该数b进制的表示形式
//题解: 运用短除法

//代码:

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



int num[100010];
int main() {
    map<char, int> mp;
    for (int i = 0; i < 10; i++)mp['0' + i] = i;
    for (int i = 0; i < 26; i++)mp['A' + i] = 10 + i;
    for (int i = 0; i < 26; i++)mp['a' + i] = 36 + i;
   string c="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int t;
    rd(t);
    while (t--) {
        int a, b,i,j;
        string s;
        rd(a);
        rd(b);
        cin >> s;
        printf("%d ", a);
        cout << s << endl;
        int l=s.size();
        for(i=0;i<l;i++)
            num[i]=mp[s[i]];
        string ans;
        loop:
            for(i=0;i<l-1;i++)
            {
                num[i+1]+=num[i]%b*a;
                num[i]/=b;
            }
            ans+=c[num[i]%b];
            num[i]/=b;
            for(j=0;j<=i&&!num[j];j++);
            if(j!=i+1)goto loop;
        reverse(ans.begin(),ans.end());
        printf("%d ",b);
        cout<<ans<<endl<<endl;
    }
}
