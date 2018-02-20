

//地址:http://poj.org/problem?id=2965
//题意:求最小次变换,把所有的'+'变成'-',对每一个点进行点击,则该行以及该列所有的点取反
//题解:对与每个'+',把该行所有的点都点击一次,该列所有的点都点击一次,则只有该点取反,其他点不变,而且易得每个点最多点1次,点两次相当于没点,
//     我们可以用滚动思想,让是否点击用 01 来变换,即每次异或1,最后求1的个数以及位置既得答案

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

int res[5][5];

int main() {
    char m;
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            cin>>m;
            if(m == '+') {
                for(int k = 1; k <= 4; ++k)
                    res[i][k] ^= 1,
                            res[k][j] ^= 1;
                res[i][j] ^= 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 4; ++j)
            if(res[i][j])
                ++cnt;
    cout<<cnt<<endl;
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 4; ++j)
            if(res[i][j])
                cout<<i<<" "<<j<<endl;
    return 0;
}
