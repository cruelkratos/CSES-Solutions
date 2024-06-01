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
  vector<vector<ll>> adj(n+1);
  for(int i = 2;i<=n;i++){
    ll parent;
    cin>>parent;
    adj[parent].push_back(i);
  }
  vll dp(n+1);
  function<ll(ll)> dfs = [&](ll int v){
    for(auto u:adj[v]){
      dp[v] += dfs(u);
    }
    return 1+dp[v];
  };
  dfs(1);
  for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';
  cout<<'\n';
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
