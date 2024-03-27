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
  ll int n,m,q;
  cin>>n>>m>>q;
  vector<vector<ll>> ans(n+1,vector<ll>(n+1,1e16));
  for(int i = 1;i<=n;i++){
    ans[i][i] = 0;
  }
  for(int i =0;i<m;i++){
    ll int x,y,z;
    cin>>x>>y>>z;
    ans[x][y] = min(ans[x][y],z);
    ans[y][x] = min(ans[x][y],z);
  }
  for(int k = 1;k<=n;k++){
    for(int i = 1;i<=n;i++){
      for(int j = 1;j<=n;j++){
        ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
      }
    }
  }
  while(q--){
    ll x ,y;
    cin>>x>>y;
    if(ans[x][y] == 1e16)cout<<-1<<'\n';
    else cout<<ans[x][y]<<'\n';
  }

}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
