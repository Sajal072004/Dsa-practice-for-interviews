#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    ll n;
    cin >> n;
    ll bSize = n * (n - 1) / 2;

    vl b(bSize);
    for (ll i = 0; i < bSize; ++i) cin >> b[i];

    sort(b.begin(), b.end());

    vl a;
    ll idx = 0;
    for (ll freq = n - 1; freq > 0; --freq) {
        a.push_back(b[idx]);
        idx += freq;
    }

    // Last element an: must be ≥ a[n-2], pick a large value
    a.push_back(1e9);

    for (auto x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
