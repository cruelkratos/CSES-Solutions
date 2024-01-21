#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> v(n);
	for(int i =0;i<n;i++){cin>>v[i].first;v[i].second=i;}
	sort(v.begin(),v.begin()+n);
	int i=0,j=n-1;
	while(i<j){
		if(v[i].first+v[j].first ==x){
			cout<<v[i].second+1<<" "<<v[j].second+1<<"\n";return;
		}
		else if(v[i].first+v[j].first < x){
			i++;
		}
		else{
			j--;
		}
	}
	cout<<"IMPOSSIBLE"<<"\n";
}
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
