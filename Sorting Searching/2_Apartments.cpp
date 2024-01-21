#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define fastfast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vll vector<ll int>
#define pll pair<ll int,ll int>
#define MOD 1000000007
 
using namespace std;
 
 
 
int main(){
	fastfast
	ll int n,m,k;
	cin>>n>>m>>k;
	ll int A[n];
	ll int B[m];
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<m;i++)
		cin>>B[i];
	sort(A,A+n);
	sort(B,B+m);
	int i=0,j=0;
	ll int count =0;
	while(i<n&&j<m){
		if(abs(A[i]-B[j])<=k){
		count++;
		i++;
		j++;}
		else if(A[i]>B[j])j++;
		else i++;
		}
		cout<<count<<endl;
	return 0;}
