#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

std::vector<ll> segTree;
void build(std::vector<ll int> &a , ll int start , ll int end,int index){
	if(start==end){
		//leaf node
		segTree[index] = a[start];
		return;
	}
	int mid = start + (end-start)/2;
	build(a,start,mid,2*index);
	build(a,mid+1,end,2*index + 1);
	segTree[index] = segTree[2*index] + segTree[2*index + 1];
 
}
 
void update(std::vector<ll int> &a , ll int start , ll int end,int index,int pos, ll val){
	if(start==end){
		a[pos] =val;
		segTree[index] = val;
		return;
 	}
	 int mid = start + (end-start)/2;
	 if(pos<=mid) update(a,start,mid,2*index,pos,val);
	 else update(a,mid+1,end,2*index + 1,pos,val);
	 segTree[index] = segTree[2*index] + segTree[2*index + 1];
}
 
long long query(ll int start , ll int end,ll int index, ll int l , ll int r){
	if(start>=l && end<=r) return segTree[index];
	if(l>end || r<start) return 0;
	ll mid = start + (end-start)/2;
	ll leftAns = query(start,mid,2*index,l,r);
	ll rightAns = query(mid+1,end,2*index +1,l,r);
	return leftAns+rightAns;
}

void solve(){
  ll int n , q;
  cin>>n>>q;
  vll a(n+1);
  for(int i = 1;i<=n;i++)cin>>a[i];
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<n-1;i++){
    ll int u , v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vll order;
  vll dp(n+1);
  vll st(n+1);
  auto dfs = [&](ll int v , ll int p , auto && dfs) -> ll{
    order.push_back(a[v]);
    st[v] = order.size()-1;
    dp[v] = 1;
    for(auto u:adj[v]){
      if(u!=p) dp[v]+= dfs(u,v,dfs);
    }
    return dp[v];
  };
  dfs(1,0,dfs);
  segTree.resize(4*n+1);
  build(order,0,n-1,1);
  while(q--){
    ll int x;
    cin>>x;
    if(x==1){
      ll int a , b;
      cin>>a>>b;
      update(order,0,n-1,1,st[a],b);
      continue;
    }
    ll z;
    cin>>z;
    cout<<query(0,n-1,1,st[z],st[z]+dp[z]-1)<<'\n';
  }
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
