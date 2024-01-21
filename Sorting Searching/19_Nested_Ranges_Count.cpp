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
bool customComparator(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) {
    if (a.first == b.first) {
        return a.second.first > b.second.first;
    }
    return a.first < b.first;
}
void solve(){
  ll int n;
  cin>>n;
  vector<pair<int,pair<int,int>>> lol(n);
  for(int i = 0;i<n;i++){
    cin>>lol[i].first>>lol[i].second.first;
    lol[i].second.second = i;
  }
  sort(lol.begin(),lol.end());
  vll a1(n,0),a2(n,0);
  pbds A,B;
  A.insert(lol[0].second.first);
  for(int i = 1;i<n;i++){
  A.insert(lol[i].second.first);
  a1[lol[i].second.second] = i - A.order_of_key(lol[i].second.first);
  }
  B.insert(lol[n-1].second.first);
  for(int i = n-2;i>-1;i--){
    a2[lol[i].second.second] = B.order_of_key(lol[i].second.first+1);
    B.insert(lol[i].second.first);
  }
  for(auto &x:a2)cout<<x<<" ";
  cout<<endl;
  for(auto &x:a1)cout<<x<<" ";
  cout<<endl;
  
}
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
