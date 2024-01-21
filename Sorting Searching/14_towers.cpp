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
	vector<int> v(n);for(int i =0;i<n;i++){cin>>v[i];}
	vector<int> lol;
	int tower =0;
	for(int i =0;i<n;i++){
		if(upper_bound(lol.begin(),lol.end(),v[i])!=lol.end()){
			ll int x = upper_bound(lol.begin(),lol.end(),v[i])-lol.begin();
			lol[x] = v[i];
		}
		else{
			tower++;
			lol.push_back(v[i]);
		}
	}cout<<tower<<endl;
	
}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}

