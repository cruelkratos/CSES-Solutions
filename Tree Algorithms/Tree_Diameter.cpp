#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

void solve(){
  ll int n;
  cin>>n;
  assert(n>0);
  vector<vector<ll>> adj(n+1);
  for(int i = 0;i<n-1;i++){
    ll a , b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vll vv(n+1);
  function<void(ll,ll)> dfs1 = [&](ll int v , ll int p){
    for(auto u: adj[v]){
      if(u!=p) {vv[u] = 1+ vv[v]; dfs1(u,v);}
    }
  };
  dfs1(1,0);
  ll furthest=0;
  ll mn = 0;
  for(int i = 1;i<=n;i++){
    if(vv[i]>mn){
      mn = vv[i];
      furthest = i;
    }
    vv[i] = 0;
  }
  dfs1(furthest,0);
  cout<<*max_element(vv.begin(),vv.end())<<endl;

}

int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
