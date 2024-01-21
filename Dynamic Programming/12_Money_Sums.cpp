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

vector<vector<int>> dp(101,vector<int>(100005,-1));
set<ll> st;
ll int n;
vll a;
int recc(ll int state , ll int sum){
  if(state==n){
    dp[state][sum] = 1;
    return 1;
  }
  if(dp[state][sum]!=-1) return dp[state][sum];
  dp[state][sum] = 1;
  recc(state+1,sum);
  recc(state+1,sum+a[state]);
  return dp[state][sum];
}

void solve(){
  cin>>n;
  a.resize(n);
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  vll ans;
  recc(0,0);
  for(int i = 1;i<=100005;i++){
    if(dp[n][i]==1){
      ans.push_back(i);
    }
  }
  cout<<ans.size()<<endl;
  for(auto &x:ans)cout<<x<<" ";
  cout<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
