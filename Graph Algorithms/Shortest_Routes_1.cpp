#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
 
void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    adj[x].push_back({y,z});
  }
  std::priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> pq;
  vector<ll> d(n+1,LLONG_MAX);d[1]=0;
  vector<bool> vis(n+1,false);
  pq.push({0,1});
  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    if(vis[p.second])continue;
    vis[p.second] = true;
    for(auto u: adj[p.second]){
      if(d[u.first] > u.second + p.first){
        d[u.first] = u.second + p.first;
        pq.push({d[u.first] , u.first});
      }
    }
  }
  for(int i = 1;i<=n;i++)cout<<d[i]<<" ";
  cout<<'\n';
  
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
