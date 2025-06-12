#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef vector<ll> vl;
typedef vector<vl> vvl;

void solve() {
    ll n, k;
    cin >> n >> k;
    vvl arr(n, vl(n));

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> arr[i][j];

    ll mismatch = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            ll ni = n - 1 - i;
            ll nj = n - 1 - j;
            if(i > ni || (i == ni && j >= nj)) continue;
            if(arr[i][j] != arr[ni][nj]) mismatch++;
        }
    }

    if(mismatch > k) {
        cout << "NO\n";
    } else if ((k - mismatch) % 2 == 0) {
        cout << "YES\n";
    } else if (n % 2 == 1) { 
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
