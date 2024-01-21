#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
using namespace std;
 
void solve(){
  ll int n;cin>>n;
  ll int cnt = 0;
  while(n>0){
    ll int mx = -1;
    ll int dup = n;
    while(dup>0){
      mx = max(mx,dup%10);
      dup/=10;
    }
    n-=mx;
    cnt++;
  }cout<<cnt<<endl;
  }	
 
int main(){
	fastfast
	ll int tt=1;
	// cin>>tt;
	while(tt--)
		solve();
	return 0;}

