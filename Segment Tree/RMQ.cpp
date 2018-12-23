#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll *tree;
ll query(ll s,ll e,ll l,ll r,ll ind)
{
    if(s>r||e<l)
    return INT_MAX;
    else if(l <= s && e <= r)
    {
        return tree[ind];
    }
    ll mid = (s+e)/2;
    return min (query(s,mid,l,r,ind*2),query(mid+1,e,l,r,ind*2+1));
    
}
void update(ll s,ll e,ll val,ll i,ll ind)
{
    if(s==e)
    {
        tree[ind]=val;
    }
    else
    {
        ll mid=(s+e)/2;
        if(i>=s&&i<=mid)
        update(s,mid,val,i,2*ind);
        else
        update(mid+1,e,val,i,2*ind+1);
        tree[ind]=min(tree[ind*2],tree[ind*2+1]);
    }
}
void build(ll ar[],ll s,ll e,ll ind)
{
    if(s==e)
    {
        tree[ind]=ar[s];
    }
    else
    {
        ll mid = (s+e)/2;
        build(ar,s,mid,2*ind);
        build(ar,mid+1,e,2*ind+1);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    ll ar[n+1];
    for(ll i=1;i<=n;i++)
    cin>>ar[i];
    tree=(ll*)malloc(3*(n)*sizeof(ll));
    build(ar,1,n,1);
    char ch;
    ll l,r;
    for(ll i=0;i<q;i++)
    {
        cin>>ch>>l>>r;
        if(ch=='q')
        cout<<query(1,n,l,r,1)<<endl;
        else
        update(1,n,r,l,1);
    }
}