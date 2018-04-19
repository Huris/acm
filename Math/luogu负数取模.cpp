


//地址：https://www.luogu.org/problemnew/show/P1017
//代码
#include <bits/stdc++.h>
using namespace std;
#define ll long long


char we[100];
string s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYXZ";
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d=",a);
    int o=0;
    do{
        int k=a%b;
        a/=b;
        if(k<0)
        {
            k-=b;
            a++;
        }
        we[o++]=s[k];
    }while(a);

    for(int i=o-1;i>=0;i--)
        printf("%c",we[i]);
    printf("(base%d)\n",b);
}
