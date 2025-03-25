//AcWing 849. Dijkstra求最短路 I
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
int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    heap.push({0,1});
    while(heap.size())
    {
        auto t = heap.top();//找到当前距离最短的点
        heap.pop();
        int ver = t.second;//表示编号
        int distance = t.first;//表示距离
        if(st[ver]) continue;
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>distance  + w[i])
            {
                dist[j] =distance  + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f) return -1;
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
    int t = dijkstra();
    printf("%d\n",t);
    return 0;
}