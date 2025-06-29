#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    ll n, x;
    cin >> n >> x;
    vl a(n+1), prefix(n+1);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    
    sort(a.begin() + 1, a.end()); 
    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }

    ll ans = 0;
    ll prev_k = -1;

    for (ll i = n; i >= 1; i--) {
        if (prefix[i] > x) continue;
        ll k = (x - prefix[i]) / i;
        if (k > prev_k) {
            ans += (k - prev_k) * i;
            prev_k = k;
        }
    }

    cout << ans << '\n';
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
