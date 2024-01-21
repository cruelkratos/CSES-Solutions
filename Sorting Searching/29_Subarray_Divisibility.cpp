#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
 
 
 
void solve(){
  ll int n;
  cin>>n;
  vll a(n);
  for(int i = 0;i<n;i++){cin>>a[i];}
  vll pref(n+1,0);
  std::map<ll,ll> m;
  m[0]++;
  ll ans = 0;
  for(int i = 1;i<=n;i++){
    pref[i] = ( (pref[i-1] + a[i-1])%n +n )%n;
    
    ans+= m[((pref[i] -n)%n +n)%n];
    // ans+=m[pref[i]];
    m[pref[i]]++;
  }
 
  cout<<ans<<endl;
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
