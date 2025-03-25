//AcWing851.spfa求最短路
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 100010;
int n,m,idx;
int h[N],ne[N],e[N],w[N];//w[]表示权重

int dist[N];//存储起点1到n的最短距离
bool st[N];
void add(int a,int b,int c)
{
    e[idx] = b, w[idx] = c, ne[idx] =h[a],h[a] = idx++;
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())
    {
        int t =q.front();
        q.pop();
        st[t] =false;
        for(int i= h[t];i!=-1;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])//j不在队列里才把它加进去
                {
                    q.push(j);
                    st[j] =true;
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);//邻接表的话重边就无所谓了，这个算法一定会找到最短的边
    }
    int t = spfa();
    if(t==-1) puts("impossible\n");
    else printf("%d\n",t);   
    return 0;
}
//这个算法也可以过AcWing850，只需要改一下58 和59就行，一般比Dijkstra速度更快,但有些出题人会把复杂度卡成nm就慢了