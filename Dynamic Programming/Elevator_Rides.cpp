// intersting bitmask dp problem
// dp[mask] -> (for a combination 'mask' {min rides,min last wt. for these rides})
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


void solve(){
  ll int n,x;
  cin>>n>>x;
  vll a(n);
  for(int i = 0;i<n;i++)cin>>a[i];
  pair<ll,ll> dp[1<<n];
  dp[0] = {1,0};
  for(int mask = 1;mask<(1<<n);mask++){
    dp[mask] = {n+1,0};
    for(ll j = 0;j<n;j++){
      if(mask&(1LL<<j)){
        auto p = dp[mask^(1LL<<j)];
        if(p.second+a[j] <=x){
          p.second += a[j];
        }
        else{
          p.first++;
          p.second = a[j];
        }
        dp[mask] = min(dp[mask],p);
      }
    }
  }
  cout<<dp[(1<<n) - 1].first<<'\n';
    
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
