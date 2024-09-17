#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >>s;
  int n = s.size();
  map<char,int>mp;
  for(auto it : s) mp[it]++;
  string ans = ""; char odd = '#'; int cnt = 0;
  for(auto it : mp){
    if(it.second % 2 == 1){ odd = it.first; cnt++;}
    ans += string(it.second / 2, it.first);
  }
  string original = ans;
  reverse(original.begin(), original.end());
  if(odd != '#' ) ans = ans + odd + original;
  else ans +=original;
  if(cnt > 1) cout << "NO SOLUTION" << endl;
  else cout << ans << endl;
  
}