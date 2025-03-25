#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N =110;
int n,m;
int g[N][N];//存储路况
int d[N][N];//某位置是第几步
PII q[N*N],Prev[N][N];//q[]实现bfs,Prev存储最终答案路径
int bfs()
{
    int hh =0,tt=0;
    q[0] = {0,0};
    memset(d,-1,sizeof(d));
    d[0][0] = 0;
    int dx[4]={-1,0,1,0},dy[4] = {0,1,0,-1};
    while(hh<=tt)
    {
        auto t = q[hh++];//下面的操作已将q[hh]的相关研究了，下次循环该研究下一个入列的了
        for(int i = 0;i<4;i++)
        {
            int x = t.first+dx[i],y=t.second+dy[i];//x和y存储现在走到的坐标
            if(x>=0 && x<n && y>=0 && y<m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] +1;//现在位置是上个位置的下一步，记录步数
                Prev[x][y] = t;//记录路径
                q[++tt] = {x,y};//将现在的位置加入队列
            }
        }
    }
    int x = n-1,y=m-1;
    while(x||y)
    {
        cout << x << ' '<< y <<endl;
        auto t = Prev[x][y];
        x=t.first,y=t.second;
    }
    return d[n-1][m-1];
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> g[i][j];
    cout << bfs()<<endl;
    return 0;
}