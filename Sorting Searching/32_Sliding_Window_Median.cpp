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
 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
void myerase(pbds &t, int v){
    int rank = t.order_of_key(v);
    pbds::iterator it = t.find_by_order(rank);
    t.erase(it);
}
void solve(){
  ll int n,k;
  cin>>n>>k;
  vll a(n);
  for(int i = 0;i<n;i++)cin>>a[i];
  pbds A;
  for(int i = 0;i<k-1;i++){
    A.insert(a[i]);
  }
  // myerase(A,a[k-1]);
  for(int i = k-1;i<n;i++){
    A.insert(a[i]);
    cout<<*A.find_by_order((k-1)/2)<<' ';
    myerase(A,a[i-k+1]);
  }
  cout<<'\n';
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
