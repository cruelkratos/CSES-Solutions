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
vll dp;
ll int n;
vector<pair<ll,pair<ll,ll>>> lol;
ll recc(ll int i){
	if(i==n) return 0;
		if(dp[i]!=-1) return dp[i];
		//don't take
		dp[i] = recc(i+1);
		//take
		ll int l = i+1;
		ll int r = n-1;
		ll int mid;
		while(l<=r){
			mid = l + (r-l)/2;
			if(lol[mid].first>lol[i].second.first){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		dp[i] = max(dp[i],lol[i].second.second + recc(l));
		return dp[i];
}
void solve(){
	cin>>n;
	lol.resize(n);
	for(int i = 0;i<n;i++){
		cin>>lol[i].first>>lol[i].second.first>>lol[i].second.second;
	}
	sort(lol.begin(),lol.end());
	dp.resize(n,-1);
	cout<<recc(0)<<endl;
}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
