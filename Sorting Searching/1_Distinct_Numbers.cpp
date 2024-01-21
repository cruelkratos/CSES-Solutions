#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vll vector<ll int>
#define pll pair<ll int,ll int>
#define MOD 1000000007
 
using namespace std;
 
 
 
void solve(){
	
		}
 
 
 
 
int main(){
	fastfast
	ll int n;
	cin>>n;
	ll int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll int count =1;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1])
			count++;
	}
	cout<<count<<endl;
		
	return 0;}

