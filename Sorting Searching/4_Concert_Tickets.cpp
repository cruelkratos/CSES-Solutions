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
	vll a(n) , b(m);
	multiset<ll> st;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	for(int i = 0;i<m;i++){
		cin>>b[i];
		
	}
	for(int i = 0;i<m;i++){
		auto it = st.upper_bound(b[i]);
		if(it==st.begin()){cout<<-1<<endl;}
		else{
		--it;
		cout<<*it<<endl;
		st.erase(it);
		}
		
	}
}
 
int main(){
	
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
