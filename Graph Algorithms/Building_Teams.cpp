#include<bits/stdc++.h>
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
 
void dfs(int v, int p, vector<vector<int>> &adj, vector<int> &classify,bool &flag){
  
  for(auto u: adj[v]){
    if(classify[u]==-1){
      classify[u] = 1 ^ classify[v];
      dfs(u,v,adj,classify,flag);
    }
 
    else if(classify[u]==classify[v]){
      flag = false;
      return;
    }
  }
}
 
void solve(){
  ll int n, m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll x,y;cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> classify(n+1,-1);
  bool flag = true;
  for(int i =1;i<=n;i++){
    if(classify[i]==-1){
      classify[i] = 0;
      dfs(i,0,adj,classify,flag);
    }
    if(!flag){
    cout<<"IMPOSSIBLE\n";return;}
  }
  
 
    for(int i = 1;i<=n;i++){
      cout<<classify[i]+1<<" ";
    }cout<<endl;
  
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
