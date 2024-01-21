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
 
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll int n;
vector<vector<ll>> dp(501,vector<ll>(125251,-1));
ll recc(ll int state , ll int sum){
	if(state==n+1){
		if(sum== ((n)*(n+1))/4) return 1;
		else return 0;
	}
	if(dp[state][sum]!=-1) return dp[state][sum];
	dp[state][sum] = recc(state+1,sum);
	dp[state][sum] = (dp[state][sum] +recc(state+1,sum+state))%MOD;
	return dp[state][sum];
}
void solve(){
	cin>>n;
	if(((n*(n+1))/2)&1){
		cout<<0<<'\n';
	}
	else{
		cout<<(recc(1,0)*binpow(2,MOD-2,MOD))%MOD<<'\n';
	}
}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
