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
 
void merge(vector<int> tree[], int treeNode)
{
    int len1 = tree[2 * treeNode].size();
    int len2 = tree[2 * treeNode + 1].size();
    int index1 = 0, index2 = 0;
 
    // Fill this array in such a
    // way such that values
    // remain sorted similar to mergesort
    while (index1 < len1 && index2 < len2) {
 
        // If the element on the left part
        // is greater than the right part
        if (tree[2 * treeNode][index1]
            > tree[2 * treeNode + 1][index2]) {
 
            tree[treeNode].push_back(
                tree[2 * treeNode + 1][index2]);
            index2++;
        }
        else {
            tree[treeNode].push_back(
                tree[2 * treeNode][index1]);
            index1++;
        }
    }
 
    // Insert the leftover elements
    // from the left part
    while (index1 < len1) {
        tree[treeNode].push_back(
            tree[2 * treeNode][index1]);
        index1++;
    }
 
    // Insert the leftover elements
    // from the right part
    while (index2 < len2) {
        tree[treeNode].push_back(
            tree[2 * treeNode + 1][index2]);
        index2++;
    }
    return;
}
 
// Recursive function to build
// segment tree by merging the
// sorted segments in sorted way
void build(vector<int> tree[], int* arr, int start, int end,
           int treeNode)
{
    // Base case
    if (start == end) {
        tree[treeNode].push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
 
    // Building the left tree
    build(tree, arr, start, mid, 2 * treeNode);
 
    // Building the right tree
    build(tree, arr, mid + 1, end, 2 * treeNode + 1);
 
    // Merges the right tree
    // and left tree
    merge(tree, treeNode);
    return;
}
 
// Function similar to query() method
// as in segment tree
int query(vector<int> tree[], int treeNode, int start,
          int end, int left, int right)
{
 
    // Current segment is out of the range
    if (start > right || end < left) {
        return 0;
    }
    // Current segment completely
    // lies inside the range
    if (start >= left && end <= right) {
 
        // as the elements are in sorted order
        // so number of elements greater than R
        // can be find using binary
        // search or upper_bound
        return tree[treeNode].end()
               - upper_bound(tree[treeNode].begin(),
                             tree[treeNode].end(), right);
    }
 
    int mid = (start + end) / 2;
 
    // Query on the left tree
    int op1 = query(tree, 2 * treeNode, start, mid, left,
                    right);
    // Query on the Right tree
    int op2 = query(tree, 2 * treeNode + 1, mid + 1, end,
                    left, right);
    return op1 + op2;
}
 
void solve(){
   int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i = 0;i<n;i++){
    cin>>arr[i];
  }
  
  int next_right[n];
    // Initialising the tree
    vector<int> tree[4 * n];
 
    map<int, int> ump;
 
    // Construction of next_right
    // array to store the
    // next index of occurrence
    // of elements
    for (int i = n - 1; i >= 0; i--) {
        if (ump[arr[i]] == 0) {
            next_right[i] = n;
            ump[arr[i]] = i;
        }
        else {
            next_right[i] = ump[arr[i]];
            ump[arr[i]] = i;
        }
    }
    // building the mergesort tree
    // by using next_right array
  build(tree, next_right, 0, n - 1, 1);
  long long ans = 0;
  for(int i =0;i<n;i++){
      ll int l = i;
      ll int r = n-1;
      ll int mid;
      while(l<=r){
          mid = l + (r-l)/2;
          if(query(tree,1,0,n-1,i,mid) <=k){
              l = mid+1;
          }
          else{
              r = mid-1;
          }
      }
    // cout<<r<<endl;
    ans+= r-i+1;
  }
  cout<<ans<<endl;
  
 
}  
 
int main(){
  fastfast
  ll int tt=1;
  // cin>>tt;
  while(tt--)
    solve();
  return 0;}
