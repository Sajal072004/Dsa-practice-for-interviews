#include <bits/stdc++.h>
using namespace std;
#define ll long long

void f() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++) v.push_back({a[i], i});
    sort(v.rbegin(), v.rend());

    vector<ll> p(n + 1);
    vector<ll> co;
    for (ll i = 1; co.size() < n; i++) {
        co.push_back(i);
        if (co.size() < n) co.push_back(-i);
    }

    for (ll i = 0; i < n; i++) p[v[i].second + 1] = co[i];

    ll ans = 0;
    for (ll i = 1; i <= n; i++) ans += 2 * abs(p[i]) * a[i - 1];

    cout << ans << "\n";
    for (ll i = 0; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) f();
    return 0;
}
