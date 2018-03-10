

//地址:http://acm.hdu.edu.cn/showproblem.php?pid=1305
//题意:给你n个字符串,判断一个字符串是否是另外一个字符串的前缀
//题解:字典树,插入过程中判断是否是前缀关系
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define bg(x) cout<<x<<"@@@"<<endl
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


char s[1000100];
int ed[1000100];
int trie[1000100*2][2];
int tot,fl;
void ins(char s[])
{
    int p=0;
    for(int i=0;s[i];i++)
    {
        int z=s[i]-'0';
        if(!trie[p][z])trie[p][z]=++tot;
        if(ed[trie[p][z]])fl=1;
        p=trie[p][z];
    }
    ed[p]=1;
    if(trie[p][0]||trie[p][1])fl=1;
}
int main()
{
    int k=1;
    while(~scanf("%s",s))
    {
        memset(ed,0, sizeof(ed));
        memset(trie,0, sizeof(trie));
        tot=fl=0;
        ins(s);
        while(scanf("%s",s))
        {
            if(s[0]=='9')break;
            if(!fl)ins(s);
        }
        printf("Set %d is ",k++);
        if(!fl)printf("immediately decodable\n");
        else printf("not immediately decodable\n");
    }
}
