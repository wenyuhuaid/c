#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n,m;
int p[N];//并查集的那个
struct Edge
{
    int a,b,w;
    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i] = {a,b,w};
    }
    sort(edges,edges+m);//所有边排序
    //初始化并查集
    for(int i=1;i<=n;i++) p[i]=i;
    //从小到大枚举所有边
    int res = 0,cnt = 0;//res存的是最小生成树的所有边的权重之和,cnt存的是当前加了多少条边
    for(int i=0;i<m;i++)
    {
        int a= edges[i].a,b = edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a!=b)//如果a到b不连通
        {
            p[a] =b;
            res +=w;
            cnt++;
        }
    }
    if(cnt < n-1) puts("impossible");//说明树不连通
    else printf("%d\n",res);
    return 0;
}