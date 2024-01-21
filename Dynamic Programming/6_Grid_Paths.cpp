#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
  ll int n;cin>>n;
  char mat[n][n];
  for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
      cin>>mat[i][j];
    }
  }
  vector<vector<ll int>> dp(n,vector<ll int>(n,0));
  for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
      if(i!=0 && j!=0){
        if(mat[i][j]!='*'){
          if(mat[i-1][j]!='*'){
            dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
          }
          if(mat[i][j-1]!='*'){
             dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
          }
        }
      }
      else{
        if(i==0 && j==0){
          if(mat[i][j]!='*'){
            dp[i][j]=1;
          }
        }
        else{
          if(i==0){
            if(mat[i][j-1]!='*' && mat[i][j]!='*'){
              dp[i][j] = dp[i][j-1];
            }
          }
          else{
            if(mat[i-1][j]!='*' && mat[i][j]!='*'){
              dp[i][j] = dp[i-1][j];
            }
          }
        }
      }
    }
  }
  cout<<dp[n-1][n-1]<<endl;
  }	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
