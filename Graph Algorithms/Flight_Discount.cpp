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



void solve(){
  ll int n,m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(int i = 0;i<m;i++){
    ll x , y , z;
    cin>>x>>y>>z;
    adj[x].push_back({y,z});
  }
  vector<vector<ll>> dp(n+1,vector<ll>(2,1e16));
  dp[1][0] = dp[1][1] = 0;
  adj[0].push_back({0,0});
  priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>> , greater<pair<ll,pair<ll,ll>>>> pq;
  pq.push({0,{1,0}});
  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    ll dis = dp[p.second.first][p.second.second];
    if(dis!=p.first) continue;
    if(p.second.first == n)break;
    ll v = p.second.first;
    ll state = p.second.second;
    for(auto u:adj[v]){
      if(!state){
        if(dp[v][state] + u.second/2 < dp[u.first][1]){
          dp[u.first][1] = dp[v][state] + u.second/2;
          pq.push({dp[u.first][1],{u.first,1}});
        }
      }
      if(dp[v][state] + u.second < dp[u.first][state]){
        dp[u.first][state] = dp[v][state] + u.second;
        pq.push({dp[u.first][state] , {u.first , state}});
      }  
    }  
  }
  cout<<dp[n][1]<<endl;


}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
