#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a, b;
    cin >> a >> b;

    ll res = LLONG_MAX;

    for (ll i = 0; i <= 32; i++) {
        ll curr_b = b + i;
        if (curr_b == 1) continue;
        ll temp = a;
        ll cnt = 0;
        while (temp > 0) {
            temp /= curr_b;
            cnt++;
        }
        res = min(res, cnt + i);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
