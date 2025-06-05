#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vin(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];
#define all(x) x.begin(), x.end()

void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    vin(a, n);
    sort(all(a));


    vl pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }


    vl suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[n - i] = suff[n - i - 1] + a[i];
    }

    ll total = pre[n];
    ll ans = 0;

    for (ll x = 0; x <= k; x++) {

        if (2 * x > n || (k - x) > n - 2 * x) continue;
        ll removed = pre[2 * x] + suff[k - x];
        ans = max(ans, total - removed);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
