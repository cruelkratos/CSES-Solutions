// Giant Parker Square shaped pizza :)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vll vector<ll>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll n , m;
int flip(int x){
    return (x>n ? x-n : x+n);
}
void solve() {
    cin >> m >> n;
    vector<vector<ll>> adj(2 * n + 1), radj(2 * n + 1);
    for (int i = 0; i < m; i++) {
        char x, y;
        int a, b;
        cin >> x >> a >> y >> b;
        if(x=='-') a+=n;
        if(y=='-') b+=n;
        adj[flip(a)].push_back(b);
        adj[flip(b)].push_back(a);
        radj[b].push_back(flip(a));
        radj[a].push_back(flip(b));
    }

    // First DFS to get the order
    vector<bool> vis1(2 * n + 1, false);
    vll order;
    auto dfs = [&](ll v, auto &&dfs) -> void {
        vis1[v] = true;
        for (auto u : adj[v])
            if (!vis1[u]) dfs(u, dfs);
        order.push_back(v);
    };

    for (int i = 1; i <= 2 * n; i++) {
        if (!vis1[i]) dfs(i, dfs);
    }

    reverse(order.begin(), order.end());

    vector<ll> vis(2 * n + 1, 0);
    ll j = 1;
    vector<vector<ll>> ord_SCC(2 * n + 1);

    // Second DFS for reverse graph
    auto SCC = [&](ll v, auto &&SCC) -> void {
        vis[v] = j;
        for (auto u : radj[v]) {
            if (vis[u] == 0) SCC(u, SCC);
        }
    };

    for (auto v : order) {
        if (vis[v] == 0) {
            SCC(v, SCC);
            j++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == vis[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<char> ans(n+1);
    vector<bool> viss(n+1);
    reverse(order.begin(),order.end());
    for(int i = 0;i<order.size();i++){
        // cout<<order[i]<<" ";
        if(order[i]>n){
            if(viss[order[i]] || viss[order[i]-n]) continue;
            order[i]-=n;
            ans[order[i]] = '-';
            viss[order[i]] = true;
        }   
        else{
            if(viss[order[i]] || viss[order[i]+n]) continue;
            ans[order[i]] = '+';
            viss[order[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fastfast;
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
