#pragma GCC optimize("O3,unroll-loops")
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

int up[200005][31]; // note: a heap allocated vector gives TLE

void solve(){
  ll int n,q;
  cin>>n>>q;
  vll a(n+1);
  for(int i = 1;i<=n;i++)cin>>a[i];
  for(int i = 1;i<=n;i++){
    up[i][0] = a[i];
  }
  for(int j = 1;j<31;j++){
    for(int i = 1;i<=n;i++){
      up[i][j] = up[up[i][j-1]][j-1];
    }
  }
  while(q--){
    ll int x,k;
    cin>>x>>k;
    for(int j = 30;j>-1;j--){
      if(k&(1<<j)){
        x = up[x][j];
      }
    }
    cout<<x<<'\n';
  }
}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
