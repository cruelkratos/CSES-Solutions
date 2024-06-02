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

void solve(){
  ll int n;
  cin>>n;
  assert(n>0);
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<n-1;i++){
    ll a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<ll> height(n+1);
  auto fill = [&](ll int v , ll int p,auto &&fill) -> ll int{
    if(adj[v].size()==1 && v!=1) return height[v] = 0;
    for(auto u:adj[v]){
      if(u!=p) height[v] = max(height[v],1+fill(u,v,fill));
    }
    return height[v];
  };
  fill(1,0,fill);
  array<pair<ll,ll> , 2> a;
  a[0] = {-1,-1};
  a[1] = {-1,-1};
  vector<array<pair<ll,ll> , 2>> dp(n+1,a);
  function<void(ll,ll)> dfs = [&](ll int v , ll int p){
    if(dp[p][0].second != v){
      dp[v][0].first = 1 + dp[p][0].first;
      dp[v][0].second = p;
    }
    else{
      dp[v][0].first = 1 + dp[p][1].first;
      dp[v][0].second = p;
    }
    for(auto u:adj[v]){
      if(u!=p){
        if(height[u]+1> dp[v][0].first){
          dp[v][1] = dp[v][0];
          dp[v][0] = {height[u]+1,u};
        }
        else if(height[u]+1> dp[v][1].first){
          dp[v][1] = {height[u]+1,u};
        }
      }
    }
    for(auto u: adj[v]){
      if(u!=p) dfs(u,v);
    }
  };
  dfs(1,0);
  for(int i = 1;i<=n;i++){
    cout<<dp[i][0].first<<" ";
  }
  cout<<endl;
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
