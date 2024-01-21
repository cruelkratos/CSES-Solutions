#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll int>
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define m2 998244353
using namespace std;
 
 
 
void solve(){
  int n;
  cin>>n;
  vector<pair<pair<int,int>,int>> lol(n);
  for(int i = 0;i<n;i++){
    cin>>lol[i].first.first>>lol[i].first.second;
    lol[i].second = i;
  }
  vll a1(n,0);
  vll a2(n,0);
  int mx = -1;
  int last = -1;
 
  for(int i = 0;i<n;i++){
    lol[i].first.second *=-1;
    
  }
  
  sort(lol.begin(),lol.end());
 
  for(int i = 0;i<n;i++){
    if(-lol[i].first.second <= mx){
      // a2[last] = 1;
      a2[lol[i].second] = 1;
    }
    mx = max(mx,-lol[i].first.second);
  }
  int mn = INT_MAX;
  for(int i = n-1;i>-1;i--){
    if(-lol[i].first.second>=mn){
      a1[lol[i].second]=1;
    }
    mn = min(mn,-lol[i].first.second);
  }
  for(int i=0;i<n;i++) cout<<a1[i]<<" "; cout<<endl;
  for(int i=0;i<n;i++) cout<<a2[i]<<" "; cout<<endl;
}
 
int main(){
  
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
