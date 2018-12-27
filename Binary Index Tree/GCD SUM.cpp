#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 1000010

ll  phi[MAX];
ll f[MAX];
ll BIT[MAX], a[MAX], n;
void sieve(){
for (ll i = 1; i < MAX; ++i)
phi[i] = i;

for (ll i = 2; i < MAX; ++i){
if(phi[i] == i)
for (ll j = i; j < MAX; j+=i)
{
phi[j]/= i;
phi[j]*= (i-1); 
}
}

for (ll i = 1; i < MAX; ++i)
for (ll j = i; j < MAX; j+=i){
f[j]+= i*phi[j/i];
if(f[j] >= mod)f[j]-= mod;
}
}
void update(ll x, ll val)
{
      for(; x <= n; x += x&-x){
        BIT[x] += val;
        if(BIT[x]>mod) BIT[x]-=mod;
      }
}
void degrade(ll x, ll val)
{
      for(; x <= n; x += x&-x)
        BIT[x] -= val;
        if(BIT[x]<0) BIT[x]=mod-BIT[x];
}
ll query(ll x)
{
     ll sum = 0;
     for(; x>0; x -= x&-x){
        sum += BIT[x];
        if(sum>mod) sum-=mod;
     }
     return sum;
}

int main()
{
    sieve();
     cin>>n;
     ll i;
     for(i = 1; i <= n; i++)
     {
           cin>>a[i];
           update(i, f[a[i]]);
     }
     ll q,l,r;
     char ch;
     cin>>q;
     for(ll i=0;i<q;i++)
     {
         cin>>ch>>l>>r;
         if(ch=='U'){
         update(l,f[r]-f[a[l]]);
         a[l]=r;
         }
         else
         {
             ll ans=query(r)-query(l-1);
             while(ans<0)
             ans+=mod;
             cout<<ans%mod<<endl;
         }
     }
     return 0;
}