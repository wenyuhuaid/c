//图的dfs
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N  = 100010,M = N*2;
int n;
int h[N],e[M],ne[M],idx;
bool st[N];
int ans = N;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a] ,h[a] = idx++;//往头插，新的指向原来的头
}
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j = e[i];
        if(!st[j]) 
        {
            int s = dfs(j);//当前子树下的联通块大小
            res = max(res,s);
            sum+=s;
        }
    }
    res =  max(res,n-sum); //把该点删后的最大联通块大小

    ans = min(ans,res);
    return sum;//返回结点数
}
int main()
{
    cin >> n;
    memset(h,-1,sizeof(h));
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);//无向边所以加入两条边
    }
    dfs(3);//dfs(n)也行
    cout << ans <<endl;
    return 0;
}