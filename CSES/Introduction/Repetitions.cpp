#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int maxi = 0;
  map<char,int>mp;
  int i = 0; int j = 0;
  while(j<s.size()){
    mp[s[j]]++;
    if(mp.size() == 1){
      maxi = max(maxi , j-i+1);
    }
    else {
      while(mp.size() > 1){
        mp[s[i]]--;
        if(mp[s[i]] == 0) mp.erase(s[i]);
        i++;
      }
    }
    j++;
  }
  cout << maxi << endl;
}