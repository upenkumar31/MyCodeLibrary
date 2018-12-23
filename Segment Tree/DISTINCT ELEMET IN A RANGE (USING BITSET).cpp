#include<bits/stdc++.h>
using namespace std;
bitset<5001> tre1[400001],tre2[400001];
bitset<5001>query1(int s,int e,int l,int r,int ind)
{
    if(s>r||e<l)
    return 0;
    else if(l <= s && e <= r)
    {
        return tre1[ind];
    }
    int mid = (s+e)/2;
    return query1(s,mid,l,r,ind*2)|query1(mid+1,e,l,r,ind*2+1);
    
}
bitset<5001>query2(int s,int e,int l,int r,int ind)
{
    if(s>r||e<l)
    return 0;
    else if(l <= s && e <= r)
    {
        return tre2[ind];
    }
    int mid = (s+e)/2;
    return query2(s,mid,l,r,ind*2)|query2(mid+1,e,l,r,ind*2+1);
    
}
void build(int ar1[],int ar2[],int s,int e,int ind)
{
    if(s==e)
    {
        tre1[ind].set(ar1[s]);
        tre2[ind].set(ar2[s]);
    }
    else
    {
        int mid = (s+e)/2;
        build(ar1,ar2,s,mid,2*ind);
        build(ar1,ar2,mid+1,e,2*ind+1);
        tre1[ind]=tre1[2*ind]|tre1[2*ind+1];
        tre2[ind]=tre2[2*ind]|tre2[2*ind+1];
    }
}
int main()
{
    int n,q;
    cin>>n;
    int ar1[n+1],ar2[n+1];
    for(int i=1;i<=n;i++)
    cin>>ar1[i];
    for(int i=1;i<=n;i++)
    cin>>ar2[i];
    build(ar1,ar2,1,n,1);
    cin>>q;
    int l1,r1,l2,r2;
    for(int i=0;i<q;i++)
    {
        cin>>l1>>r1>>l2>>r2;
        cout<<(query1(1,n,l1,r1,1)|query2(1,n,l2,r2,1)).count()<<endl;
    }
}