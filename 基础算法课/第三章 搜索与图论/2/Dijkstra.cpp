//AcWing 849. Dijkstra求最短路 I
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
int n,m;
int g[N][N];
int dist[N];//存储起点1到n的最短距离
bool st[N];
int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<n;i++)
    {
        int t = -1;
        for(int j = 1;j<=n;j++)
            if(!st[j] && ((t==-1) || dist[t]>dist[j]))
                t=j;
        st[t] = true;
        for(int j = 1;j<=n;j++)
            dist[j] = min(dist[j],dist[t]+g[t][j]);//这就是为啥上面初始化0x3f3f3f，没路就保持dist[j];
            //dist[t]（1到t的距离是得到了的）如果1到t再到j的距离比1到j曾经存储的最短距离短则刷新
    }
    if(dist[n] == 0x3f3f3f) return -1;
    return dist[n];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof(g));
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = min(g[a][b],c);
    }
    int t = dijkstra();
    printf("%d\n",t);
    return 0;
}