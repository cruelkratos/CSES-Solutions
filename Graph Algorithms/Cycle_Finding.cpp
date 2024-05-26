#include<bits/stdc++.h>
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
 
class edge{
  public:
  ll a;
  ll b;
  ll c;
};
 
void solve(){
  ll int n , m;
  cin>>n>>m;
  vector<vector<pair<ll,ll>>> adj(n+1),radj(n+1);
  vector<edge> ed(m);
  for(int i=0;i<m;i++){
    cin>>ed[i].a>>ed[i].b>>ed[i].c;
    adj[ed[i].a].push_back({ed[i].b,ed[i].c});
    radj[ed[i].b].push_back({ed[i].a,ed[i].c});
  }
  vector<ll> dis(n+1,1e16),par(n+1,0);
  dis[1] = 0;
  for(int i = 0;i<n-1;i++){
    for(auto &e:ed){
      if(dis[e.b]>dis[e.a]+e.c){
        dis[e.b] = dis[e.a]+e.c;
        par[e.b] = e.a;
      }
    }
  }
  bool f = true;
  ll dd = -1;
  for(auto &e:ed){
    if(dis[e.b]>dis[e.a]+e.c){
        dis[e.b]>dis[e.a]+e.c;
        par[e.b] = e.a;
        dd = e.b;
        f = false;
        break;
      }
  }
  if(f){
    cout<<"NO\n";
    return;
  }
  
  cout<<"YES\n";
  vector<bool> vis(n+1,false);
  vector<ll> a = {dd};
  while(!vis[dd]){
    vis[dd] = true;
    dd = par[dd];
    a.push_back(dd);
  }
  reverse(a.begin(),a.end());
  ll x = a[0];
  cout<<a[0]<<" ";
  for(int i = 1;i<a.size();i++){
    if(a[i]!=x)cout<<a[i]<<" ";
    else{
      cout<<x<<endl;
      return;
    }
  }
}
int main(){
  fastfast;
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
