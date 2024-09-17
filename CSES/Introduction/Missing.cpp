#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int miss = 0;
  for(int i = 0; i<n-1; i++){
    int x; cin >>x; miss ^=x;
  }
  int total = 0;
  for(int i = 1; i<=n; i++)  total ^= i;
  cout <<( miss^ total);
}