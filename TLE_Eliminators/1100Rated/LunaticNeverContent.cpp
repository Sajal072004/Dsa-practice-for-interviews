#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vin(v, n) for (int i = 0; i < n; ++i) cin >> v[i];

bool isPalindrome(vector<ll> &arr, ll x) {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i++] % x != arr[j--] % x)
            return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vin(a, n);

    ll g = 0;
    for (int i = 0; i < n / 2; ++i) {
        g = gcd(g, abs(a[i] - a[n - i - 1]));
    }

    if (g == 0) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    
    for (ll d = 1; d * d <= g; ++d) {
        if (g % d == 0) {
            if (isPalindrome(a, d)) ans = max(ans, d);
            if (isPalindrome(a, g / d)) ans = max(ans, g / d);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
