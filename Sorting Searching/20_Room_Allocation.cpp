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
  int n;
  cin>>n;
  vector<pair<pair<int,int>,int>> lol(n);
  for(int i = 0;i<n;i++){
    cin>>lol[i].first.first>>lol[i].first.second;
    lol[i].second = i;
  }
  sort(lol.begin(),lol.end());
  vll ans(n);
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  // priority_queue<pair<int,int>> pq;
  pq.push({INT_MAX,0});
  int last = 0;
  for(int i = 0;i<n;i++){
 
    // cout<<pq.top().first<<" "<<pq.top().second<<endl;
 
    if(pq.top().first < lol[i].first.first){
      int x = pq.top().second;
      pq.pop();
      pq.push({lol[i].first.second , x});
      ans[lol[i].second] = x;
    }
    else{
      pq.push({lol[i].first.second , ++last});
      ans[lol[i].second] = last;
    }
  }
  cout<<last<<endl;
  for(auto it:ans) cout<<it<<" ";
  cout<<endl;
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
