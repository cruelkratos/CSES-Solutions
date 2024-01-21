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
	ll int mx = -9e18;
	ll int curr =0;
	for(int i =0;i<n;i++){
		curr+=v[i];
		mx = max(curr,mx);
		if(curr<0){curr=0;}
	}
	cout<<mx<<"\n";
	}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
