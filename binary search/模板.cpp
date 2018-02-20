



#数组单调递增
//返回大于等于x的数中最小的一个 <==> lower_bound
int Greater_equal(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]>=x)r=mid;else l=mid+1;
    }
    return l;
}
//返回大于x的数中最小的一个 <==> upper_bound
int Greater(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]>x)r=mid;else l=mid+1;
    }
    return l;
}
//返回小于等于x的数中最大的一个
int Smaller_equal(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(a[mid]<=x)l=mid;else r=mid-1;
    }
    return l;
}
//返回小于x的数中最大的一个
int Smaller(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(a[mid]<x)l=mid;else r=mid-1;
    }
    return l;
}

#数组单调递减
//返回大于等于x的数中最小的一个(从右往左第一个)
//如果是从左往右第一个,则直接判第一个数与x的大小即可
int Greater_equal(int a[],int x,int l,int r)
{
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(a[mid]>=x)l=mid;else r=mid-1;
    }
    return l;
}
//返回大于x的数中最小的一个(从右往左第一个)
//如果是从左往右第一个,则直接判第一个数与x的大小即可
int Greater(int a[],int x,int l,int r)
{
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(a[mid]>x)l=mid;else r=mid-1;
    }
    return l;
}
//返回小于等于x的数中最大的一个(从左往右)
int Smaller_equal(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=x)r=mid;else l=mid+1;
    }
    return l;
}

//返回小于x的数中最大的一个(从左往右)
int Smaller(int a[],int x,int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]<x)r=mid;else l=mid+1;
    }
    return l;
}
