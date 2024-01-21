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
  vll a(n);
  for(int i =0;i<n;i++){cin>>a[i];}
  vector<ll int> dp(x+1,MOD);
  dp[0]=0;
  for(int i =1;i<=x;i++){
    for(int j =0;j<n;j++){
      if(i>=a[j]){
        dp[i] = min(dp[i],dp[i-a[j]]+1);
      }
      
    }
  }
  if(dp[x]==MOD){
    cout<<-1<<endl;
  }
  else{
    cout<<dp[x]<<endl;
  }
  }	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
