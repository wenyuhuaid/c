#include<iostream>
	using namespace std;
	const int N=1e6+10;
	int n;
	int q[N];
void quick_sort(int q[],int l,int r)
{
    if(l>=r)return ;
    int x=q[l],i=l-1,j=r+1;//不能取q[r]
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
        /*没有swap函数的话
        if(i<j){
            int t= q[i];
            q[i]=q[j];
            q[j]=t;
        }
        */
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
    /*如果不用j用i的话
    quick_sort(q,l,i-1);
    quick_sort(q,i,r);
    并且这个函数第二行int x=q[(r+l+1)/2]或者x=q[r];不能取到q[l]
    */
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i<n;i++)scanf("%d",&q[i]);

    quick_sort(q,0,n-1);
    for(int i = 0 ; i<n;i++)printf("%d ",q[i]);

    return 0;
}
