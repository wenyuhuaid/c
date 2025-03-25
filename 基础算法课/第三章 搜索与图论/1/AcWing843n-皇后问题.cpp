
#include<iostream>
using namespace std;
const int N =20;
int n;
char g[N][N];
bool col[N],dg[2*N],udg[2*N];
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !dg[u+i] && !udg[n-u+i])
        {
            g[u][i] = 'Q';
            col[i]=dg[u+i]=udg[n-u+i] = true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i] = false;
            g[u][i] = '.';
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}
/*
#include<iostream>
using namespace std;
const int N = 21; // 将N改为21，因为索引从1开始，需要多一个空间
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n + 1) { // 终止条件改为u == n + 1
        for (int i = 1; i <= n; i++) puts(g[i] + 1); // 输出从1开始
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) { // 列索引从1开始
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { // 行索引从1开始
        for (int j = 1; j <= n; j++) { // 列索引从1开始
            g[i][j] = '.';
        }
    }
    dfs(1); // 从1开始
    return 0;
}

*/