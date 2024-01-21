#pragma GCC optimize("O3")
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
  ll int n,x;
  cin>>n>>x;
  vector<pair<ll,ll>> lol(n);
  for(int i = 0;i<n;i++){
    cin>>lol[i].first;
    lol[i].second = i+1;
  }
  sort(lol.begin(),lol.end());
  map<ll,vector<pair<ll,ll>>> m;
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      m[lol[i].first + lol[j].first].push_back({i,j});
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      if(m[x-lol[i].first - lol[j].first].size()!=0){
        for(auto it: m[x-lol[i].first - lol[j].first]){
          if(i!=it.first && j!=it.second && j!=it.first && i!=it.second){
            
            cout<<lol[i].second<<" "<<lol[j].second<<" "<<lol[it.first].second<<" "<<lol[it.second].second<<endl;
            return;
          }
        }
      }
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
