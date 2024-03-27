#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
 
int dfs(vector<vector<int>> &a,int n,int m,int i , int j){
	if(i<0 ||i>=n || j<0 || j>=m) return 0;
	if(a[i][j]==0) return 0;
	a[i][j] = 0;
	dfs(a,n,m,i-1,j);
	dfs(a,n,m,i,j-1);
	dfs(a,n,m,i,j+1);
	dfs(a,n,m,i+1,j);
	return 1;
 
}
 
void solve(){
	ll int n,m;
	cin>>n>>m;
	vector<vector<int>> a (n,vector<int>(m));
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			char x;cin>>x;
			if(x=='#') a[i][j]=0;
      else a[i][j]=1;
		}
	}
	int ans  = 0;
	for(int i = 0 ;i<n;i++){
		for(int j=0;j<m;j++){
			ans += dfs(a,n,m,i,j);
		}
	}
  cout<<ans<<'\n';
 
}
 
int main(){
	
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
