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
  int N, M;
  cin >> N >> M;
  vector<int> dist(N + 1, INT_MAX), parent(N + 1);
  vector<vector<int>> adj(N + 1);
  while (M--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int t : adj[x])
      if (dist[t] == INT_MAX) {
        dist[t] = dist[x] + 1;
        parent[t] = x;
        q.push(t);
      }
  }
  if (dist[N] == INT_MAX) cout << "IMPOSSIBLE";
  else {
    cout << dist[N] + 1 << "\n";
    vector<int> v{N};
    while (v.back() != 1) v.push_back(parent[v.back()]);
    reverse(begin(v), end(v));
    for (int t : v) cout << t << " ";
  }
 
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
