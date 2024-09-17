#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  long long mod = 1e9 + 7; 
  cin >> n;
  long long ans = 1;
  long long base = 2;
  while(n>0){
    if(n&1) ans = (ans%mod * base%mod)%mod;
    base = (base%mod * base%mod)%mod; n/=2;
    
  }
  cout << ans%mod << endl;
}