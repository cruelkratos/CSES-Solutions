#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<endl
#else
#define debug(x)
#endif
 
template <class T> void _print(T a) {cerr<<a;}
template <class T> void _print(vector<T> v1){
cerr<<"[ ";
for(auto it: v1)
cerr<<it<<" ";
cerr<<"]";}
 
 
void solve(){
	ll int n;
	cin>>n;
	vector<pair<ll,ll>> kr;
	for(ll i = 0;i<n;i++){
		ll int a,b;
		cin>>a>>b;
		kr.push_back(make_pair(a,1));
		kr.push_back(make_pair(b,-1));
	}
	ll int ans =0;
	sort(kr.begin(),kr.end());
	ll int y = kr[0].first;
	ll int curr  = 1;
	for(auto it: kr){
		if(it.second ==1){
			if(it.first!=kr[0].first){
				curr++;
			}
		}
		else{
			curr--;
		}
		ans = max(ans,curr);
	}
	cout<<ans<<endl;
	}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
