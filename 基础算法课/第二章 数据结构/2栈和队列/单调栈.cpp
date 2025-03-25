#include<iostream>
//Acwing830 单调栈
using namespace std;
const int N=100010;
int n;
int stk[N],tt;
int main()
{
    cin >> n;//可以优化:第一种 前面加 ios:::sync_with_stdio(false);
   // scanf("%d",&n);第二种 更快 后面输出也改成printf
    for(int i = 0; i< n;i++)
    {
        int x;
        cin >> x;
        while(tt && stk[tt]>=x) tt--;
        if(tt) cout << stk[tt] << ' '; 
        else cout << -1 << endl; 
        stk[++tt]=x;
    }
    return 0;
}