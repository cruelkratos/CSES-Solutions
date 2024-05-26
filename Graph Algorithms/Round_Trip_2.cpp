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
  vector<vector<ll>> adj(n+1);
  for(int i=0;i<m;i++){
    ll int x , y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  vector<ll> color(n+1,0);
  vector<ll> par(n+1,0);
  auto dfs = [&](ll int v,auto &&dfs) -> ll{
    color[v] = 1;
    for(auto u : adj[v]){
      par[u] = v;
      if(color[u]==1){
        return u;
      }
      else if(color[u]==0){
        ll z = dfs(u,dfs);
        if(z>0) return z; 
      }
    }
    color[v] = 2; 
    return 0;
  };
  bool f = true;
  ll j = 0;
  for(int i = 1;i<=n;i++){
    if(color[i]==0){
      j = dfs(i,dfs);
      if(j>0){
        f = false;
        break;
      }
    }
  }
  if(f){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  vll ans = {j};
  ll d = par[j];
  while(d!=j){
    ans.push_back(d);
    d = par[d];
  }
  ans.push_back(j);
  cout<<ans.size()<<endl;
  for(int i = ans.size()-1;i>-1;i--){
    cout<<ans[i]<<" ";
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
