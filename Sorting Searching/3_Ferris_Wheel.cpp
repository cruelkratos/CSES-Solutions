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

void solve(){
  ll int n,x;
  cin>>n>>x;
  vll a(n);
  for(auto &i: a)cin>>i;  
  sort(a.begin(),a.end());
  ll int i = 0,j = n-1;
  ll g = 0;
  while(i<j){
    if(a[i] + a[j] <=x){
      g++;
      i++;--j;
    }
    else j--;
  }
  cout<< g + (n-2*g)<<endl;
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
