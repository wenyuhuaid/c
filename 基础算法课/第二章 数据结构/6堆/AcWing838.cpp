#include<iostream>
#include<algorithm>
using namespace std;
const int N =100010;
int n,m;
int h[N],size;//h[1]开始便利计算，对于h[x]，左儿子为2x,右儿子为2x+1,size为元素个数
void down(int u)
{
    int t=u;
    if(u*2 <=::size && h[u*2]<h[t]) t=u*2;
    if(u*2+1 <=::size && h[u*2+1]<h[t]) t=u*2+1;
    if(u != t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}
void up(int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        swap(h[u/2],h[u]);
        u/=2;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&h[i]);
    ::size=n;
    for(int i = n /2 ; i;i--) down(i);//n/2一定在倒数第二排
    while(m--)
    {
        printf("%d ",h[1]);
        h[1] = h[::size];
        ::size--;
        down(1);
    }
}
