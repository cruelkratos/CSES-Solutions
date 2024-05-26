#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
 
void solve(){
  ll int n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  vector<ll> dp(n+1,-1);
  function<ll(ll)> dfs = [&](ll int v) ->ll{
    if(v==n) return 1;
    if(dp[v]!=-1) return dp[v];
    dp[v] = 0;
    for(auto u: adj[v]){
      dp[v] = (dp[v] + dfs(u))%MOD;
    }
    return dp[v];
  };
  cout<<dfs(1)<<endl;
}
int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
