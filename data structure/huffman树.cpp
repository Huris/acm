#include <stdio.h>
#include <string>
#include <queue>
#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define pic pair<int,char>


const int N=1e6+7;
struct node
{
    char c;       //结点的字符
    int weight;    //结点的权重
    int lc,rc;    //结点的左孩子和右孩子
    int fa;       //结点的父亲
    int i;       //结点的下标
    //构造函数
    node(int w=0,char cc='\0',int l=0,int r=0,int p=0,int ii=0)
    {
        weight=w;lc=l;rc=r;fa=p;c=cc;i=ii;
    }
    //结构体比较
    bool operator<(const node &k)const
    {
        if(weight!=k.weight)return weight>k.weight;
        else return c>k.c;
    }
}e[N];
string word[N];     //输入文章
string wword[N];    //huffman编码
string huffman_code[N]; //输入huffman编码
string huffman[N];  //记录每个字符对应的huffman编码
priority_queue<node>que;
pic num[N];
int o=0;     //o记录文本的行数
int node_num;  //huffman叶子结点数
int node_sum;  //huffman总结点数
void init()
{
    for(int i=0;i<N;i++)huffman[i].clear();
    for(int i=0;i<N;i++)wword[i].clear();
    node_num=0;
    o=0;
    node_sum=0;
}
void huffman_coding()   //huffman编码
{
    init();     //初始化
    ifstream infile;infile.open("C://Users//A//Desktop//article1.txt");
    ofstream outfile;outfile.open("C://Users//A//Desktop//huffman2.txt");
    o=0;
    while(getline(infile,word[o++]));  //输入文本,以文件结束为标志
    for(int i=0;i<o;i++)    //记录每个字符出现的频率
    {
        for(int j=0;j<word[i].size();j++)
        {
            char c=word[i][j];
            num[c].first++;
            num[c].second=c;
        }
    }
    sort(num,num+N);    //将出现次数从小到大排序
    int i=0;
    while(num[i].first==0)i++;  //找到第一个存在的字符
    node_num=0;     //node_num记录字符数
    while(i<N)      //保存字符
    {
        e[node_num]=node(num[i].first,num[i].second,0,0,0,node_num);
        que.push(e[node_num]);
        node_num++;
        i++;
    }
    node_sum=node_num*2-1;      //huffman树总的结点数node_sum
    for(i=node_num;i<node_sum;i++)
    {
        node s1=que.top();que.pop();    //取出两个最小的结点
        node s2=que.top();que.pop();
        e[i].lc=s1.i;       //分别设为左孩子和右孩子
        e[i].rc=s2.i;
        e[i].i=i;   //记录当前结点的编号
        e[s1.i].fa=e[s2.i].fa=i;    //将孩子的父亲设为当前结点
        e[i].weight=e[s1.i].weight+e[s2.i].weight; //当前父亲的权重设为孩子结点的权重之和
        que.push(e[i]); //将父亲插入到优先队列中
    }
    for(i=0;i<node_num;i++)
    {
        int fa=e[i].fa; //自底向上求huffman编码
        int nw=i;
        while(fa)
        {           //如果该结点为左孩子,则编码加0,否则加1
            if(e[fa].lc==nw)huffman[e[i].c]+='0';
            else if(e[fa].rc==nw)huffman[e[i].c]+='1';
            nw=e[fa].i;     //递归父亲结点
            fa=e[fa].fa;
        }
        reverse(huffman[e[i].c].begin(),huffman[e[i].c].end());   //需要反转编号
    }
    cout<<"各字符对应的huffman编码为:"<<endl;
    for(int i=0;i<M;i++)
    {
        if(huffman[i].size())
            cout<<char(i)<<":"<<huffman[i]<<endl;
    }
    cout<<"本文对应的huffman编码已在文件夹中"<<endl;
    outfile<<"本文对应的huffman编码为:"<<endl;
    for(int i=0;i<o;i++)
    {
        for(int j=0;j<word[i].size();j++)
        {
            outfile<<huffman[word[i][j]];
            wword[i]+=huffman[word[i][j]];
        }
        outfile<<endl;
    }
    outfile.close();
    outfile.open("C://Users//A//Desktop//huffman1.txt");
    for(int i=0;i<o-1;i++)
        outfile<<wword[i]<<endl;
    outfile<<wword[i];
    outfile.close();
    cout<<"编码成功~"<<endl;
}
void huffman_decoding()     //huffman解码
{
    ifstream infile;infile.open("C://Users//A//Desktop//huffman1.txt");
    ofstream outfile;outfile.open("C://Users//A//Desktop//article2.txt");
    int o=0;
    while(getline(infile,huffman_code[o++]));
    outfile<<"该huffman编码对应的文章是:"<<endl;
    for(int i=0;i<o;i++)
    {
        int nw=node_sum-1;
        for(int j=0;j<huffman_code[i].size();j++)
        {
            if(e[nw].lc==e[nw].rc&&e[nw].lc==0)
            {
                outfile<<e[nw].c;
                nw=node_sum-1;
            }
            if(huffman_code[i][j]=='0')nw=e[nw].lc;
            else nw=e[nw].rc;
        }
        outfile<<e[nw].c<<endl;
    }
    infile.close();
    outfile.close();
    cout<<"本huffman编码对应的原文已在文件中~"<<endl;
    cout<<"解码成功~"<<endl;
}
int menu()	//菜单函数
{
	int choice;
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("~*--------赫夫曼编码与压缩---------*~\n");
	printf("~*       1.从文件编码              *~\n");
	printf("~*       2.从文件解码              *~\n");
	printf("~*       0.退出                    *~\n");
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("请输入选项:");
	scanf("%d",&choice);
	getchar();
	return choice;
}
int main()
{
    int flag=0;
    while(1)
    {
        system("cls");
        int select=menu();
        switch(select)
        {
            case 1:huffman_coding();flag=1;break;
            case 2:if(flag==0)cout<<"抱歉,必须先编码才能解码,请重新输入!"<<endl;
                   else huffman_decoding();flag=0;
                   break;
            default: cout<<"bye bye~~"<<endl;return 0;
        }
        system("pause");
    }
}
