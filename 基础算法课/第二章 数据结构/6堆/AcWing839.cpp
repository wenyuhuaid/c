//模拟堆
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N =100010;
int h[N],size,ph[N],hp[N];//ph[k]记录第k个插入的数在堆里的下标，hp[k]堆里面第k个点是第几个插入的点

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u)
{
    int t=u;
    if(u*2 <=::size && h[u*2]<h[t]) t=u*2;
    if(u*2+1 <=::size && h[u*2+1]<h[t]) t=u*2+1;
    if(u != t)
    {
        heap_swap(u,t);//heap_swap里面就不要写h[u],h[t]这种了，只需u,t,head_swap函数会实现它
        down(t);
    }
}
void up(int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        heap_swap(u/2,u);
        u/=2;
    }
}
int main()
{
   int n,m=0;
   scanf("%d",&n);
   while(n--)
   {
    char op[10];
    int k,x;
    scanf("%s",op);
    if(!strcmp(op,"I"))
    {
        scanf("%d",&x);
        ::size++;
        m++;//当前是第几个插入的数
        ph[m] = ::size,hp[::size] = m;
        h[::size] = x;
        up(::size);
    }
    else if(!strcmp(op,"PM")) printf("%d\n",h[1]);
    else if(!strcmp(op,"DM"))
    {
        heap_swap(1,::size);
        ::size--;
        down(1);
    }
    else if(!strcmp(op,"D"))
    {
        scanf("%d",&k);
        k=ph[k];
        heap_swap(k,::size);
        ::size--;
        down(k),up(k);
    }
    else 
    {
        scanf("%d%d",&k,&x);
        k=ph[k];
        h[k]=x;
        down(k),up(k);
    }
   }
   return 0;
}
