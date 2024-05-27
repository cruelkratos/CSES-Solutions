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
  for(int i = 0;i<m;i++){
    ll int u ,v;
    cin>>u>>v;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  vector<bool> vis(n+1);
  vll order;
  auto dfs = [&](ll int v , auto &&dfs) -> void{
    vis[v] = true;
    for(auto u:adj[v]){
      if(!vis[u]) dfs(u,dfs);
    }
    order.push_back(v);
  };
  for(int i = 1;i<=n;i++){
    if(!vis[i])dfs(i,dfs);
  }
  reverse(order.begin(),order.end());
  vector<ll int> vis2(n+1,0);
  ll int k = 1;
  auto kosaraju = [&](ll int v , auto &&kosaraju) -> void{
    vis2[v] = k;
    for(auto u:radj[v]){
      if(vis2[u]==0) kosaraju(u,kosaraju);
    }
  };
  for(auto &v: order){
    if(vis2[v]==0){
      kosaraju(v,kosaraju);
      k++;
    }
  }
  cout<<k-1<<endl;
  for(int i = 1;i<=n;i++)cout<<vis2[i]<<" ";
  cout<<endl;
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
