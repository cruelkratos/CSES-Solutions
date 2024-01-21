#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	ll int n,x;
	cin>>n>>x;
	vll c(n);
	for(int i =0;i<n;i++){
		cin>>c[i];
	}
	vector<ll int> dp(x+1,0);
	dp[0]++;
	for(int i =1;i<=x;i++){
		for(int j = 0;j<n;j++){
			if(i>=c[j]){
				dp[i] =  (dp[i] + dp[i-c[j]])%MOD;
			}
			
		}
	}
	cout<<dp[x]<<endl;
	}	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
