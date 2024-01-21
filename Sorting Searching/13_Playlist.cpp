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
	map<int,int> mp;
	int j = 0;
	int ans = 0;
	for(int i =0;i<n;i++){
		while(j<n&&(mp[v[j]]==0)){
			mp[v[j]]++;
			j++;
		}
		ans = max(ans,j-i);
		mp[v[i]]--;
	}cout<<ans<<"\n";
	
}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
