#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0;i<n;i++){cin>>v[i];}
	ll int ans = 0;
	sort(v.begin(),v.begin()+n);
	for(int i =0;i<n;i++){
		ans += abs(v[i]-v[n/2]);
	}
	cout<<ans<<"\n";
	}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
