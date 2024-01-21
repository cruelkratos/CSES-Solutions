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
 
 
void solve(){
  ll int n;
  cin>>n;
  vll a(n);
  ll total = 0;
  for(int i = 0;i<n;i++){cin>>a[i];total+=a[i];} 
  sort(a.begin(),a.end());
  if(total - a[n-1] < a[n-1]){
    cout<<2*a[n-1]<<endl;
  }
  else{
    cout<<total<<endl;
  }
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
