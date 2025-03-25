#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26],cnt[N],idx;//26是儿子的所有情况,cnt是存储该字母结尾的字符串出现了多少次
char str[N];
void insert(char str[])
{
    int p = 0;//从根节点（0）开始
    for(int i = 0;str[i];i++)
    {
        int u = str[i]-'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p]++;
}
//返回字符串出现了多少次
int query(char str[])
{
    int p= 0;
    for(int i=0;str[i];i++)
    {
        int u = str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if(op[0]=='I') insert(str);
        else printf("%d\n",query(str));
    }
    return 0;
}
