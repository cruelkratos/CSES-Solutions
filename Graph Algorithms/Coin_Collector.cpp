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
  vector<vector<ll>> adj(n+1) , radj(n+1);
  vll a(n+1);
  for(int i = 1;i<=n;i++)cin>>a[i];
  for(int i = 0;i<m;i++){
    ll int x , y;
    cin>>x>>y;
    adj[x].push_back(y);
    radj[y].push_back(x);
  }
  vector<bool> pass(n+1);
  vector<ll> order;
  auto dfs = [&](ll int v , auto &&dfs) -> void{
    pass[v] = true;
    for(auto u:adj[v]){
      if(!pass[u]) dfs(u,dfs);
    }
    order.push_back(v);
  };
  for(int i = 1;i<=n;i++){
    if(!pass[i])dfs(i,dfs);
  }
  reverse(order.begin(),order.end());
  vll num(n+1,0);
  ll int j = 1;
  auto SCC = [&](ll int v , auto&&SCC) -> void{
    num[v] = j;
    for(auto u:radj[v]){
      if(num[u]==0) SCC(u,SCC);
    }
  };
  for(auto &u: order){
    if(num[u]==0){
      SCC(u,SCC);
      j++;
    }
  }
  vector<vector<ll>> DAG(j+1);
  vll cost(n+1);
  for(int i = 1;i<=n;i++){
    cost[num[i]] += a[i];
  }
  for(int i = 1;i<=n;i++){
    for(auto v: adj[i]){
      if(num[i]!=num[v]){
        DAG[num[i]].push_back(num[v]);
      }
    }
  };
  vll dp(n+1,-1);
  auto recc = [&](ll int v , auto &&recc) -> ll{
    if(DAG[v].size()==0) return dp[v] = cost[v];
    if(dp[v]!=-1) return dp[v];
    ll ans = 0;
    for(auto u:DAG[v]) {
      ans = max(ans,recc(u,recc));
    }
    return dp[v] = cost[v]+ans;
  };
  ll ans = 0;
  for(int i = 1;i<j;i++){
    ans = max(ans,recc(i,recc));
  }
  cout<<ans<<endl;
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
