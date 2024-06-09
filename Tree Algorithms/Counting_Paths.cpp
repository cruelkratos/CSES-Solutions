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
  ll int n , m;
  cin>>n>>m;
  vector<ll> parent(n+1);
  vector<vll> adj(n+1);
  for(int i = 0;i<n-1;i++){
    ll int a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vll dp(n+1);
  auto dfs = [&](ll int v,ll int p, auto&&dfs)-> void{
    parent[v] = p;
    for(auto u:adj[v])
    if(u!=p){dp[u] = 1 + dp[v];dfs(u,v,dfs);}
  };
  dfs(1,0,dfs);
  int LOG = __lg(n) + 1;
  vector<vector<ll>> up(n+1,vector<ll>(LOG));
  for(int i = 0;i<=n;i++)up[i][0] = parent[i];
  for(int j = 1;j<LOG;j++){
    for(int i = 1;i<=n;i++){
      up[i][j] = up[up[i][j-1]][j-1];
    }
  }
  auto lca = [&](ll int p , ll int q) -> ll{
    if(dp[p]<dp[q]) swap(p,q);
    ll hike = dp[p] - dp[q];
    for(int j = 0;j<LOG;j++){
      if(hike&(1<<j)) p = up[p][j];
    }
    if(p==q){
      return p;
    }
    ll dis = 0;
    for(int j = LOG-1;j>-1;j--){
      if(up[p][j]!=up[q][j] && up[q][j] && up[p][j]){
        p = up[p][j];
        q = up[q][j];
        dis |= (1<<j);
      }
    }
    return up[p][0];
  };
  vll diff(n+1);
  dp[0] = -1;
  for(int i = 0;i<m;i++){
    ll int a , b;
    cin>>a>>b;
    ll int x = lca(a,b);
    diff[a]++;
    diff[b]++;
    diff[x]--;
    diff[up[x][0]]--;
  }
  vll ans(n+1);
  adj[1].push_back(0);
  auto recc = [&](ll int v,ll int p, ll int d,auto &&recc) -> ll{
    ans[v] = diff[v];
    for(auto u:adj[v]){
      if(p!=u){
        ans[v] += recc(u,v,d+diff[v],recc);
      }
    }
    return ans[v];
  };
  recc(1,0,0,recc);
  for(int i = 1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
