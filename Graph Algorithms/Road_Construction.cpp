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
 
vector<ll> parent,Size;
ll int comp;
ll sz = 1;
int find(int x){
  if(parent[x]==x) return x;
  return parent[x] = find(parent[x]);
}
 
void union_sets(int a, int b) {
  comp--;
  a = find(a);
  b = find(b);
  if (a != b) {
    if (Size[a] < Size[b])
      swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
    sz = max(sz,Size[a]);
  }
}
 
void solve(){
  ll int n,m;
  cin>>n>>m;
  comp = n;
  parent.resize(n+1);
  for(int i = 1;i<=n;i++)parent[i] = i;
  Size.resize(n+1,1);
  for(int i = 0;i<m;i++){
    ll int a , b;
    cin>>a>>b;
    if(find(a)==find(b)) cout<<comp<<" "<<sz<<'\n';
    else{
      union_sets(a,b);
      cout<<comp<<" "<<sz<<'\n';
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
