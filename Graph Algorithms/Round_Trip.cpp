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
map<int,vector<int>> adj;
vector<bool> vis;
vector<int> ans;
bool dfs(int v,int p){
  vis[v] = true;
  for(auto u: adj[v]){
    if(u!=p){
      ans.push_back(u);
      if(!vis[u]){
        if(dfs(u,v)) return true;
      }
      else{
        return true;
      }
      ans.pop_back();
      
    }
    
  }
  
  return false;
}
 
void solve(){
  int n , m;
  cin>>n>>m;
  for(int i = 0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vis.resize(n+1,false);
  for(int i =1;i<=n;i++){
    if(!vis[i]){
    ans.push_back(i);
    if(dfs(i,0)){
    vll vec;
    ll x = ans[ans.size()-1];
    vec.push_back(x);
  for(int i = ans.size()-2;i>=0;i--){
    if(ans[i]==x){
      vec.push_back(x);
      break;
    }
    vec.push_back(ans[i]);
  }
  cout<<vec.size()<<endl;
  for(auto it:vec){
    cout<<it<<" ";
  }cout<<endl;
  return;
  }
  ans.pop_back();
    }
    
  }
  
  
    cout<<"IMPOSSIBLE\n";
  
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
