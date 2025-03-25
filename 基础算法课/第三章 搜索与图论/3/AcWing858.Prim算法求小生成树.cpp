#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510,INF = 0x3f3f3f3f;
int n,m;
//题是稠密图，用邻接矩阵来存储
int g[N][N];
int dist[N];
bool st[N];
int prim()
{
    memset(dist,0x3f,sizeof dist);//把所有距离初始化为正无穷
    int res = 0;//最小生成树的所有边的长度之和
    for(int i = 0;i<n;i++)
    {
        int t = -1;
        for(int j = 1;j<=n;j++)
        {
            if(!st[j] && (t==-1|| dist[t]>dist[j]))//必须在集合外 当前还未找到任何一个点 t的距离大于j的距离
                t = j;//循环结束后t存的是距离最小的点
        }
        if( i  && dist[t] == INF) return INF;//如果不是第一个点的话且t（距集合最近的点）的距离是正无穷，说明图不连通
        if(i) res +=dist[t];//这个必须在下行代码的上面，如果在其后面，出现自环会出问题
        for(int j = 1;j<=n;j++) dist[j] = min(dist[j],g[t][j]);
        st[t] = true;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] =g[b][a] = min(g[a][b],c);
    }
    int t=prim();
    if(t==INF) puts("impossible");
    else printf("%d\n",t);
    return 0;
}