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
  ll int n;
  cin>>n;
  vll a(n);
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  stack<pair<ll,ll>> s;
  vll ans(n,-1);
  for(int i = n-1;i>-1;i--){
    if(s.empty()){
      s.push({a[i],i});
    }
    else{
      while(!s.empty()){
        if(s.top().first > a[i]){
          ans[s.top().second] = i;
          s.pop();
        }
        else{
          break;
        }
      }
      s.push({a[i],i});
    }
  }
  for(int i = 0;i<n;i++){
    cout<<ans[i]+1<<" ";
  }cout<<"\n";
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
