


1.指针版
struct node
{
    int val;  //数据
    node *pre,*next;  //指针
};
node *head,*tail;
void initialize()  //新建链表
{
    head=new node();
    tail=new node();
    head->next=tail;
    tail->pre=head;
}
void insert(node *p,int val)  //在p后插入包含数据val的新结点
{
    node *q;
    q=new node();
    q->val=val;
    p->next->pre=q;
    q->next=p->next;
    p->next=q;
    q->pre=p;
}
void remove(node *p)  //删除p
{
    p->pre->next=p->next;
    p->next->pre=p->pre;
    delete p;
}
void recycle()      //链表回收内存
{
    while(head!=tail)
    {
        head=head->next;
        delete head->pre;
    }
    delete tail;
}




2.数组版
const int SIZE=1e5+7;
struct node
{
    int val;  //数据
    int pre,next; //指针
}vex[SIZE];
int head,tail,tot;
void initialize()  //新建链表
{
    tot=2;
    head=1;tail=2;
    vex[head].next=tail;
    vex[tail].pre=head;
}
void insert(int p,int val)  //在p后插入包含数据val的新结点
{
    int q=++tot;
    vex[q].val=val;
    vex[vex[p].next].pre=q;
    vex[q].next=vex[p].next;
    vex[p].next=q;
    vex[q].pre=p;
}
void remove(int p)  //删除p
{
    vex[vex[p].pre].next=vex[p].next;
    vex[vex[p].next].pre=vex[p].pre;
}
void clear()      //链表清空
{
    memset(vex,0,sizeof(vex));
    head=tail=tot=0;
}
