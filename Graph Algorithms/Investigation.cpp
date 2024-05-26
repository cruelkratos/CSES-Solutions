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
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll int u,v,x;
    cin>>u>>v>>x;
    adj[u].push_back({v,x});
  }
  vll dis(n+1,1e15);
  dis[1] = 0;
  std::priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq,q;
  pq.push({0,1});
  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    if(dis[p.second] != p.first) continue;
    for(auto u: adj[p.second]){
      if(dis[u.first] > dis[p.second] + u.second){
        dis[u.first] = dis[p.second] + u.second;
        pq.push({dis[u.first],u.first});
      }
    }
  }
  vector<std::array<ll,3>> ans(n+1,{0,LLONG_MAX,LLONG_MIN});
  ans[1][0] = 1;
  ans[1][1] = 0;
  ans[1][2] = 0;
  q.push({0,1});
  vll d(n+1,1e15);
  d[1] = 0;
  while(!q.empty()){
    auto p = q.top();
    q.pop();
    if(d[p.second] != p.first) continue;
    for(auto u: adj[p.second]){
      if(d[u.first] > d[p.second] + u.second){
        d[u.first] = d[p.second] + u.second;
        q.push({d[u.first],u.first});
      }
      if(dis[u.first]==dis[p.second] + u.second){
        // cout<<u.first<<" "<<p.second<<" "<<u.second<<endl;
        ans[u.first][0] = (ans[u.first][0] + ans[p.second][0])%MOD;
        ans[u.first][1] = min(ans[u.first][1] ,1 + ans[p.second][1]);
        ans[u.first][2] = max(ans[u.first][2] ,1 + ans[p.second][2]);
      }
    }
  }
  cout<<dis[n]<<" "<<ans[n][0]<<" "<<ans[n][1]<<" "<<ans[n][2]<<endl;
}
int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
