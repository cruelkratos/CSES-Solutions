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
 
ll int dp[5001][5001];
ll recc(ll int i , ll int j,string &s1, string &s2){
  if(i==s1.size())return s2.size()-j;
  if(j==s2.size())return s1.size()-i;
  if(dp[i][j]!=-1)return dp[i][j];
  ll ans = 0;
  if(s1[i]==s2[j]){
    ans =  recc(i+1,j+1,s1,s2);
  }
  else{
    ans = 1+ recc(i+1,j+1,s1,s2);
    ans = min(ans,1+recc(i+1,j,s1,s2));
    ans = min(ans,1+recc(i,j+1,s1,s2));
  }
  return dp[i][j] = ans;
}
 
void solve(){
  string s1,s2;
  cin>>s1;
  cin>>s2;
  memset(dp,-1,sizeof(dp));
  ll x= recc(0,0,s1,s2);
  cout<<x<<endl;
 
}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
