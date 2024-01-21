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
  ll int n;
  std::cin>>n;
  vector<ll> a(n);
  for(int i = 0;i<n;i++)cin>>a[i];
  vector<ll> b;
  for(int i = 0;i<n;i++){
    if(lower_bound(b.begin(),b.end(),a[i])==b.end()){
      b.push_back(a[i]);
    }
    else{
      ll int j = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
      b[j] = a[i];
    }
  }
  cout<<b.size()<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
