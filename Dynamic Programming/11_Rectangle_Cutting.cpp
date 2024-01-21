#pragma GCC optimize ("O3")
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

vector<vector<int>> dp(501,vector<int>(501,-1));

ll recc(ll int x , ll int y){
  if(x==y) return 0LL;
  if(dp[x][y]!=-1) return dp[x][y];
  ll ans = MOD;
  for(int i = 1;i<=x/2;i++){
    ans = min(ans,1+recc(x-i,y) + recc(i,y));
  }
  for(int i = 1;i<=y/2;i++){
    ans = min(ans,1+recc(x,i)+recc(x,y-i));
  }
  return dp[x][y] =ans;
}

void solve(){
  ll int x , y;
  std::cin>>x>>y;
  cout<<recc(x,y)<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
