#include <bits/stdc++.h>
using namespace std;

int main(){
  long long t; cin>>t;
  while(t--){
    long long y,x; cin >> x >> y; long long ans;

    long long firstrow;
    if(x&1) firstrow = 1 + 4*((x/2)*(x/2));
    else firstrow = 4*((x/2)*(x/2));

    long long firstcol;
    if(y&1) firstcol = (y*y);
    else firstcol = (y*(y-2)) + 2;

    if(x < y){
      if(y&1) ans = firstcol - x + 1;
      else ans = firstcol + x - 1;
    }
    else {
      if(x&1) ans = firstrow + y - 1;
      else ans = firstrow - y + 1;
    }

    cout << ans << endl;





  }
}