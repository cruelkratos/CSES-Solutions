#include <bits/stdc++.h>
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


/*
Possible Iterative(change 1 to delete cost/insert cost/etc..)

int Solution::minDistance(string A, string B) {
    const int n = A.size();
    const int m = B.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,1000000));
    dp[0][0] = 0;
    for(int i =1;i<=n;i++)dp[i][0] = i;
    for(int i = 1;i<=m;i++)dp[0][i] = i;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(A[i-1]==B[j-1])dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}
// Possible Space Opimisation : O(min(n,m)) 
*/
