#include<iostream>
using namespace std;
const int N = 100010;
//head表示头结点的下标
//e[i]表示节点i的值
//ne[i]表示节点i的next指针是多少
//idx存储当前已经用到了哪个点的下一个点
int head,e[N],ne[N],idx;
void init()
{
    head= -1;
    idx= 0;
}
//将x插到头结点
void add_to_head(int x)
{
    e[idx]=x;//e[0]=x
    ne[idx]=head;//此时的head=-1,相当于指向空
    head=idx;//指向头结点
    idx++;//已用了自然自增
}//此时e[0]=x,head=0,ne[0]=-1,idx=1;
//将x插到下标是k的点后面
void add(int x,int k)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[x]=idx;
    idx++;
}
//将下标是k的点的后面的点删掉
void remove(int k)
{
    if(!k) head=ne[head];
    else  ne[k]=ne[ne[k]];
}