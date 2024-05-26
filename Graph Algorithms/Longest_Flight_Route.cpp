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
  ll int n,m;
  cin>>n>>m;
  vector<ll> adj[n+1];
  for(int i = 0;i<m;i++){
    ll x , y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  vector<ll> dp(n+1,-1);
  function<ll(ll)>dfs = [&](ll int v) -> ll{
    if(v==n) return 1LL;
    if(dp[v]!=-1) return dp[v];
    dp[v] = LLONG_MIN;
    for(auto u:adj[v]){
      dp[v] = max(1+dfs(u),dp[v]);
    }
    return dp[v];
  };
  dfs(1);
  if(dp[1]<1){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  dp[n] = 1;
  cout<<dp[1]<<endl;
  // for(int i = 0;i<=n;i++)cout<<dp[i]<<" ";
  ll int z = 1;
  while(z!=n){
    cout<<z<<" ";
    ll j = 0;
    for(auto u:adj[z]){
      if(dp[u]>dp[j]){
        j = u;
      }
    }
    z = j;
  }
  cout<<n<<endl;
}
int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
