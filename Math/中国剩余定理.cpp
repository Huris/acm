

设m[1],m[2],...,m[n]是两两互质的整数,m=πm[i],M[i]=m/m[i],t[i]是线性同余方程M[i]t[i]=1(mod m[i])的一个解,
对于任意n个整数a[1],a[2],...,a[n],方程组
                            x=a[1](mod m[1])
                            x=a[2](mod m[2])
                            ...
                            x=a[n](mod m[n])
有整数解,解为x=∑a[i]M[i]t[i]


证明:
    因为M[i]=m/m[i]是除了m[i]之外所有模数的倍数,所以对任意的k(k不等于i),a[i]M[i]t[i]=0(mod m[k]),
    又因为a[i]M[i]t[i]=a[i](mod m[i]),所以带入x=∑a[i]M[i]t[i],原方程成立


代码:
ll china(int n)  //m[i]模数,r[i]余数,n个数
{
    ll a,b,c,c1,c2,x,y,d;
    a=m[0];c1=r[0];
    if(c1==0)c1=m[0];
    for(int i=1;i<n;i++)
    {
        b=m[i];c2=r[i];
        d=exgcd(a,b,x,y);
        c=c2-c1;
        if(c%d)return -1;
        ll b1=b/d;
        x=((c/d*x)%b1+b1)%b1;   //最小整数解
        c1=a*x+c1;	//新方程的c1
        a=a*b1;		//新方程的a
    }
    return c1;
}
