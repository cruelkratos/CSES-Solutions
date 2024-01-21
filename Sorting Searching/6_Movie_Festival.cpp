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
	vector<pair<int,int>> k(n);
	for(int i =0;i<n;i++){cin>>k[i].second>>k[i].first;}
	sort(k.begin(),k.end());
	int temp = 0;
	int ans = 0;
	for(int i =0;i<n;i++){
		if(temp<=k[i].second){ans++;temp = k[i].first;}
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
