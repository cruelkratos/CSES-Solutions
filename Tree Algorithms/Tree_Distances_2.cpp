#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
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
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<n-1;i++){
    ll int x , y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vll dp(n+1);
  vll ans(n+1);
  auto dfs = [&](ll int v , ll int p , ll int d, auto &&dfs) -> void{
    dp[v] = 1;
    ans[1] += d;
    for(auto u:adj[v]){
      if(u!=p){
        dfs(u,v,1+d,dfs);
        dp[v] += dp[u];
      }
    }
  };
  dfs(1,0,0,dfs);
  function<void (ll,ll)> recc = [&](ll int v , ll int p) {
    if(v!=1){
      ans[v] += ans[p] - (dp[v]-1); // my subtree
      ans[v] +=  (n-1-dp[v]); // through rest
    }
    for(auto u:adj[v]){
      if(u!=p) recc(u,v);
    }
  };
  
  recc(1,0);
  for(int i = 1;i<=n;i++) cout<<ans[i]<<" ";
  cout<<'\n';
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
