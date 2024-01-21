#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	ll int n;
	cin>>n;
	vector<ll int> dp(n+1);
	dp[0] = 1;
	for(int i = 1;i<=n;i++){
		dp[i]=0;
		for(int j = 1;j<=6;j++){
			if(i-j>=0){
				dp[i] = (dp[i-j] + dp[i])%MOD;
			}
		}
	}
	cout<<dp[n]<<endl;
	}	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
