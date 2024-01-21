#pragma GCC optimize ("O3")
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
 
bool check(ll int mid ,vll &a, ll int k){
  ll sum = 0;
  ll z=0;
  for(auto &it: a){
    if(sum+it > mid){
      z++;
      sum = 0;
    }
    sum+=it;
  }
  z++;
  return k>=z;
}
 
void solve(){
  ll int n , k;
  cin>>n>>k;
  vector<ll> a(n);
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  ll int l = *max_element(a.begin(),a.end());
  ll int r = accumulate(a.begin(),a.end(),0LL);
  ll int mid;
  while(l<=r){
    mid = l + (r-l)/2;
    if(check(mid,a,k)){
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  // cout<<check(8,a,3)<<endl;
  cout<<l<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
