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
 
vector<int> parent,Rank;
 
int find(int x){
  if(parent[x]==x) return x;
  return parent[x] = find(parent[x]);
}
 
void union_sets(int a , int b){
  ll A = find(a);
  ll B = find(b);
  if(A!=B){
    if(Rank[A] == Rank[B]){
      parent[B] = A;
      Rank[A]++;
    }
    if(Rank[A] < Rank[B]) swap(A,B);
    parent[B] = A;
  }
}
 
void solve(){
  ll int n,m;
  cin>>n>>m;
  vector<vector<ll int>> adj(n+1);
  vector<pair<ll,pair<ll,ll>>> edge(m);
  for(int i = 0;i<m;i++){
    ll int a , b ,c;
    cin>>a>>b>>c;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge[i] ={c,{a,b}};
  }
  vector<bool> vis(n+1,false);
  function<void(ll int)> dfs = [&](ll int v){
    vis[v] = true;
    for(auto u:adj[v]){
      if(!vis[u]) dfs(u);
    }
  };
  dfs(1);
  for(int i = 1;i<=n;i++){
    if(!vis[i]){
      cout<<"IMPOSSIBLE\n";
      return;
    }
  }
  parent.resize(n+1);
  Rank.resize(n+1);
  for(int i = 1;i<=n;i++)parent[i] = i;
  ll cost = 0;
  sort(edge.begin(),edge.end());
  for(int i = 0;i<m;i++){
    if(find(edge[i].second.first) != find(edge[i].second.second)){
      cost += edge[i].first;
      union_sets(edge[i].second.first , edge[i].second.second);
    }
  }
  cout<<cost<<endl;
}
 
int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
