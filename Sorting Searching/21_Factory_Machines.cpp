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
 
bool f(ll int mid, vll &k ,ll int t){
  ll int n = k.size();
  ll int p =0;
  for(int i = 0;i<n;i++){
    p+= mid/k[i];
  }
  return t<=p;
}
 
void solve(){
  ll int n,t;
  cin>>n>>t;
  vll k(n);
  for(int i = 0;i<n;i++){
    cin>>k[i];
  }
  sort(k.begin(),k.end());
  ll int l = 0;
  ll int r = t*k[0];
  ll mid;
  while(l<=r){
    mid = l + (r-l)/2;
    if(f(mid,k,t)){
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  cout<<l<<endl;
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
