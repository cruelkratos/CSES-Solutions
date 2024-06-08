#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;


void solve(){
  ll int n , q;
  cin>>n>>q;
  vector<ll> parent(n+1);
  for(int i = 0;i<n-1;i++){
    ll p;
    cin>>p;
    parent[i+2] = p;
  }
  int LOG = __lg(n) + 1;
  vector<vector<ll>> up(n+1,vector<ll>(LOG));
  for(int i = 0;i<=n;i++)up[i][0] = parent[i];
  for(int j = 1;j<LOG;j++){
    for(int i = 1;i<=n;i++){
      up[i][j] = up[up[i][j-1]][j-1];
    }
  }
  while(q--){
    ll int x , k;
    cin>>x>>k;
    for(int j = 0;j<LOG;j++){
      if(k&(1<<j)){
        x = up[x][j];
      }
    }
    if(x==0){
      cout<<-1<<'\n';
      continue;
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
