#include<iostream>
using namespace std;
const int N =100010;
int n,m;
int p[N];
int size1[N];
int find(int x)
{
    if(p[x] != x) p[x] =find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i<=n; i++) 
    {
        p[i]=i;
        size1[i]=1;
    }
    while(m--)
    {
        char op[5];
        int a,b;
        scanf("%s",op);
        if(op[0] == 'C') {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))continue;
            size1[find(b)] +=size1[find(a)];
            p[find(a)] = find(b);

        }
        else if (op[1]== '1')
        {
            scanf("%d%d",&a,&b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            scanf("%d",&a);
            printf("%d\n",size1[find(a)]);

        }
    }
    return 0;
}

