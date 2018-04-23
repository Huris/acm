

//地址:https://www.luogu.org/problemnew/show/P2480
//题意:猪王国的文明源远流长，博大精深。iPig在大肥猪学校图书馆中查阅资料，得知远古时期猪文文字总个数为N。
       当然，一种语言如果字数很多，字典也相应会很大。当时的猪王国国王考虑到如果修一本字典，规模有可能远远超过康熙字典，
       花费的猪力、物力将难以估量。故考虑再三没有进行这一项劳猪伤财之举。当然，猪王国的文字后来随着历史变迁逐渐进行了简化，去掉了一些不常用的字。
       iPig打算研究古时某个朝代的猪文文字。
       根据相关文献记载，那个朝代流传的猪文文字恰好为远古时期的k分之一，其中k是N的一个正约数（可以是1和N）。
       不过具体是哪k分之一，以及k是多少，由于历史过于久远，已经无从考证了。iPig觉得只要符合文献，每一种能整除N的k都是有可能的。
       他打算考虑到所有可能的k。显然当k等于某个定值时，该朝的猪文文字个数为N / k。
       然而从N个文字中保留下N / k个的情况也是相当多的。
       iPig预计，如果所有可能的k的所有情况数加起来为P的话，那么他研究古代文字的代价将会是G的P次方。
        现在他想知道猪王国研究古代文字的代价是多少。由于iPig觉得这个数字可能是天文数字，所以你只需要告诉他答案除以999911659的余数就可以了。
//题解:中国剩余定理+lucas定理
      WA了n发......
      首先,自己的Lucas模板会超时.....
      第二个坑点,指数的模与整个自身的模差1

//代码:
const ll mod=999911658;
ll m[4]={2,3,4679,35617},r[4];
ll poww(ll a,ll b,ll c){ll ans=1; for(a%=c;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}
ll p[105555];
ll x,y;
ll ans;
void init()
{
    int i;
    for(p[0]=i=1;i<=100010;i++)p[i]=p[i-1]*i%mod;
}
ll lucas(ll n,ll m,ll mod)
{
    ll ans=1;
    while(n&&m)
    {
        ll nn=n%mod;
        ll mm=m%mod;
        if(nn<mm) return 0;
        ans=ans*p[nn]*poww(p[mm]*p[nn-mm]%mod,mod-2,mod)%mod;
        n/=mod;
        m/=mod;
    }
    return ans;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b) {  x=1; y=0;return a; }
    ll d=exgcd(b,a%b,y,x); y-=x*(a/b);return d;
}
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
int main()
{
    init();
    ll n,g;
    cin>>n>>g;
    g%=mod+1;
    if(g==0)
    {
        printf("0\n");
        return 0;
    }
    ll nn=sqrt(n);
    for(ll i=1;i<=nn;i++)
    {
        if(n%i==0)
        {
            for(int j=0;j<4;j++)r[j]=(r[j]+lucas(n,i,m[j]))%m[j];
            if(i*i!=n)for(int j=0;j<4;j++)r[j]=(r[j]+lucas(n,n/i,m[j]))%m[j];
        }
    }
    printf("%lld\n",poww(g,china(4),mod+1));
}
