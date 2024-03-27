#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
 
struct triple{
  ll int a , b , c;
};
 
void solve(){
  ll int n,m;
  cin>>n>>m;
  std::vector<triple> edge(m);
  vector<vll> adj1(n+1),adj2(n+1);
  for(int i = 0;i<m;i++){
    cin>>edge[i].a>>edge[i].b>>edge[i].c;
    adj1[edge[i].b].push_back(edge[i].a);
    adj2[edge[i].a].push_back(edge[i].b);
  } 
  vll d(n+1,-1e17);
  d[1] = 0;
  for(int i = 0;i<n-1;i++){
    for(auto e:edge){
      d[e.b] = max(d[e.b],d[e.a]+e.c);
    }
  }
  vector<bool> vis1(n+1,false),vis2(n+1,false),vis3(n+1,false);
  for(auto e:edge){
    if(d[e.b]<d[e.a]+e.c)vis1[e.b] = true;
  }
  std::function<void(ll,vector<bool>&, vector<vll>&)>dfs = [&](ll int v,vector<bool>&vis, vector<vll>&adj){
    vis[v] = true;
    for(auto u:adj[v]){
      if(!vis[u])dfs(u,vis,adj);
    }
  };
  dfs(n,vis2,adj1);
  dfs(1,vis3,adj2);
  for(int i = 0;i<=n;i++){
    if(vis2[i]&&vis1[i]&&vis3[i]){
      cout<<-1<<endl;
      return;
    }
  }
  cout<<d[n]<<endl;
 
}
 
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
