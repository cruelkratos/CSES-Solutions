#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int> lol;
  vector<int>children;
  for(int i =0;i<n;i++){
    lol.push_back(i+1);
  }
  int print = 0;
  int count = 0;
 
    while(lol.size()>=1){
      for(auto it:lol){
        if(count&1){
          cout<<it<<" "; 
        }
        else{
          children.push_back(it);
        }
        count++;
      }
      lol = children;
      children.clear();
    }
  
}

