#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dijkstra(vector<ll> *adj,map<pair<ll,ll>,ll> &weight,ll start,ll n)
{
		priority_queue<pair<ll,ll> > pq;
		vector<ll> dist(n);
		fill(dist.begin(),dist.end(),LONG_LONG_MAX);
		pq.push(make_pair(0,start));
		dist[start]=0;
		while(!pq.empty())
		{
			pair<ll,ll> temp=pq.top();
			pq.pop();
			int u=temp.second;
			vector<ll>::iterator it;
			for(it=adj[u].begin();it!=adj[u].end();it++)
			{
				if (dist[*it]>dist[u]+weight[make_pair(u,*it)])
				{
					dist[*it]=dist[u]+weight[make_pair(u,*it)];
					pq.push(make_pair(dist[*it],*it));	
				}
			}
		}

		for(ll i=0;i<dist.size();i++)
			cout<<dist[i]<<" ";
}
int main()
{
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n];
    map<pair<ll,ll>,ll > weight;
    for(ll i=0;i<m;i++)
    {
    	ll x,y,z;
    	cin>>x>>y>>z;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    	weight[make_pair(x,y)]=z;
    	weight[make_pair(y,x)]=z;
    }
    dijkstra(adj,weight,0,n);
}