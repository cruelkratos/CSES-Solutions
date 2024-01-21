#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	ll int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0;i<n;i++){cin>>v[i];}
	sort(v.begin(),v.end());
	vector<ll int> pref(n);pref[0]=v[0];
	for(int i =1;i<n;i++){pref[i]=pref[i-1]+v[i];}
	if(v[0]!=1){cout<<1<<endl;}
	else{
		for(int i =1;i<n-1;i++){
			if(v[i+1]>pref[i]+1){
				cout<<pref[i]+1<<endl;return;
			}
		}
		cout<<pref[n-1]+1;
	}
}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
