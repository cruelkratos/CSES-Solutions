#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
 
int main(){
	
	fastfast
	int n,x;
	cin>>n>>x;
	vector<int> a(n),b(n);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		cin>>b[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1));
	for(int i = 0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i = 0;i<=x;i++){
		dp[0][i] = 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j>=a[i-1]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i-1]] + b[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}cout<<dp[n][x]<<endl;
	return 0;}

