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
 
 
ll int n;
ll dp[5001][5001][2];
vll a;
ll recc(ll int i , ll int j,ll int c){
	if(j<i) return 0;
  if(dp[i][j][c]!=-1) return dp[i][j][c];
  ll int ans = 0;
  if(!c){
  ans = a[i]+recc(i+1,j,1^c);
  ans = max(ans , a[j]+recc(i,j-1,1^c));
  }
  else{
  ans = recc(i+1,j,1^c);
  ans = min(ans , recc(i,j-1,1^c));
  }
  return dp[i][j][c] = ans; 
}  
 
void solve(){
  cin>>n;
  a.resize(n);
  memset(dp,-1,sizeof(dp));
  for(int i = 0;i<n;i++)cin>>a[i];
  cout<<recc(0,n-1,0)<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
