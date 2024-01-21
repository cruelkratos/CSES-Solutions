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
  vector<pair<ll,ll>> lol(n);
  for(int i = 0;i<n;i++){
    cin>>lol[i].first>>lol[i].second;
  }
  sort(lol.begin(),lol.end());
  ll int ans1 = lol[0].second;
  for(int i = 1;i<n;i++){
    lol[i].first+= lol[i-1].first;
    ans1+=lol[i].second;
  }
  ll int ans2=0;
  for(auto it: lol){
    ans2+= it.first;
  }
  cout<<ans1-ans2<<endl;
 
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
