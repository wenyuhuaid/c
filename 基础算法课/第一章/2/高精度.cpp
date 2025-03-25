#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//假定AB都是正整数
bool cmp(vector<int>&A,vector<int>&B)
{
    if(A.size()!=B.size()) return A.size()>B.size();
    for(int i = A.size()-1 ;i>=0;i--)
        if(A[i]!=B[i]) return A[i]>B[i];
    return true;
}
//高精度减法C=A-B;(这里的A>B>0)
vector<int> sub(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    for(int i = 0,t =0;i<A.size();i++)
    {
        t = A[i] - t;
        if(B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0) t =1;
        else t = 0;
    }
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}
//高精度加法
vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int>C;
//第二种写法： if(A.size()<B.size())return add(B,A);
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++)//这里就可以把i<B.size()去掉
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);
    return C;
}

//高精度乘法
vector <int>mul(vector<int> &A,int b)
{
    vector<int>C;
    int t = 0;
    for(int i = 0 ; i< A.size()|| t ; i++)
    {
        if(i<A.size()) t+=A[i] * b;
        C.push_back(t%10);
        t/=10;
    }
    return C;
}
//高精度除法     A/b  商C 余数是r
vector <int>div(vector<int> &A,int b,int& r)
{
  vector<int>C;
  r=0;
  for(int i= A.size()-1;i>=0;i--)
  {
    r=r*10+A[i];
    C.push_back(r/b);
    r%=b;
  }
  reverse(C.begin(),C.end());
  while(C.size()>1 && C.back()==0) C.pop_back();
  return C;
}
vector<int> div(vector<int>&A,int b, int & r)
{
    vector<int>C;
    r= 0;
    for(int i = A.size()-1;i>=0;i--)
    {
        r= r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    string a,b;
    vector<int>A,B;
    cin >> a>> b;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    //高精度加法
    auto C=add(A,B);
    for(int i=C.size()-1;i>=0;i--)printf("%d",C[i]);
    cout <<endl;

    //高精度减法
    if(cmp(A,B))
    {
        auto C= sub(A,B);
        for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    else
    {
        auto C=sub(B,A);
        printf("-");
        for(int i =C.size()-1;i>=0;i--)printf("%d",C[i]);
    }

    //高精度除法
    string a2;
    int b2;
    cin >> a2>>b2;
    vector<int> A2;
    for(int i=a2.size()-1;i>=0;i--) A2.push_back(a2[i]-'0');
    int r;
    auto D2=div(A2,b2,r);
    for(int i = D2.size()-1;i>=0;i--)printf("%d",D2[i]);
    cout << endl<<r<<endl;

    return 0;
}