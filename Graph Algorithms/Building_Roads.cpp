#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
 
void dfs(vector<vector<int>> &adj,vector<bool> &vis,int v){
	for(auto u: adj[v]){
		if(!vis[u]){
			vis[u]= true;
			dfs(adj,vis,u);
		}
	}
}
 
void solve(){
	ll int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	for(int i = 0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<bool> vis(n+1,false);
	vector<int> road;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			road.push_back(i);
			vis[i] = true;
			dfs(adj,vis,i);
		}
	}
	cout<<road.size()-1<<endl;
	for(int i = 0;i<road.size()-1;i++){
		cout<<road[i]<<" "<<road[i+1]<<endl;
	}
}
 
int main(){
	
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}
