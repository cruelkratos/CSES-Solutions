#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;
 
  vector<vector<int>> dp(n+1,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0) {
	(dp[i][j] += dp[i][left]) %= MOD;
      }
    }
  }
  cout << dp[n][target] << endl;
	}	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}

