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
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
 
 
void solve(){
  ll int n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  vll vis(n+1,0);
  auto dfs = [&](ll int v,auto &&dfs) ->bool{
    vis[v] = 1;
    bool ans = true;
    for(auto u:adj[v]){
      if(vis[u]==0){
        ans &= dfs(u,dfs);
      }
      if(vis[u]==1) return false;
    }
    vis[v] = 2;
    return ans;
  };
  for(int u = 1;u<=n;u++){
    if(!vis[u]){
      if(!dfs(u,dfs)){
        cout<<"IMPOSSIBLE\n"; return;
      }
    }
  }
  for(int i = 0;i<=n;i++)vis[i] = 0;
  vll hi;
  auto dfs1 = [&](ll int v,auto &&dfs1) ->void{
    vis[v] = 1;
    bool ans = true;
    for(auto u:adj[v]){
      if(vis[u]==0){
        dfs1(u,dfs1);
      }
    }
    hi.push_back(v);
    vis[v] = 2;
  };
  for(int i =1;i<=n;i++){
    if(vis[i]==0){
      dfs1(i,dfs1);
    }
  }
  reverse(hi.begin(),hi.end());
  for(int i =0;i<hi.size();i++)cout<<hi[i]<<" ";cout<<endl;
} 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
