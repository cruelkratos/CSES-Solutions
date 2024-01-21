#pragma GCC optimize("O3")
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
 
 
 
void solve(){
	ll int n,m;
	cin>>n>>m;
	vll a(n+1);
	a[0]=0;
	vll v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		a[v[i]] = i;
	}
	ll ans = 1;
	unordered_set<ll> s;
	for(int i = 1;i<=n;i++){
		if(a[i]<a[i-1]){
			ans++;
			s.insert(i);
		}
	}
	
	a.push_back(MOD);
	for(int i = 0;i<m;i++){
		ll int x,y;
		cin>>x>>y;
		if(s.find(v[x-1] +1) !=s.end()) {ans--;
		s.erase(v[x-1]+1);
		}
		if(s.find(v[x-1]) !=s.end()) {ans--;
		s.erase(v[x-1]);
		}
		if(s.find(v[y-1] +1) !=s.end()) {ans--;
		s.erase(v[y-1]+1);
		}
		if(s.find(v[y-1]) !=s.end()) {ans--;
		s.erase(v[y-1]);
		}
		
		swap(a[v[x-1]] , a[v[y-1]]);
		swap(v[x-1],v[y-1]);
		if(a[v[x-1]] <a[v[x-1] -1] ){
			ans++;
			s.insert(v[x-1]);
		}
		if(a[v[x-1]] > a[v[x-1] +1] ){
			ans++;
			s.insert(v[x-1] +1);
		}
		if(a[v[y-1]] <a[v[y-1] -1] && s.find(v[y-1])==s.end()){
			ans++;
			s.insert(v[y-1]);
		}
		if(a[v[y-1]] > a[v[y-1] +1] && s.find(v[y-1] +1)==s.end()){
			ans++;
			s.insert(v[y-1] +1);
		}
		cout<<ans<<endl;
	}
	 
	
}
 
int main(){
	
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
