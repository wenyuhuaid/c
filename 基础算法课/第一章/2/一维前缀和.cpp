#include<iostream>
using namespace std;
const int N = 100010;
int n,m;
int a[N],s[N];
//一维前缀和
//题目为Acwing795
int main()
{
    //ios::sync_with_stdio(false);//这个的作用是让cin>>的速度变快但无法使用scanf且依然没有scanf快
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    while(m--)
    {
        int l ,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}