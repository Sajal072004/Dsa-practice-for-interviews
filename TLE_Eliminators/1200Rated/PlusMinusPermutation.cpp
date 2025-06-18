#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

ll lcm(ll a, ll b) {
    return (a * b)/ __gcd(a, b);
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll cx = n / x;
    ll cy = n / y;
    ll cxy = n / lcm(x, y);

    ll onlyX = cx - cxy;
    ll onlyY = cy - cxy;

    // Assign largest `onlyX` numbers to x-multiples → n, n-1, ..., n-onlyX+1
    // Sum of largest k numbers: k * (2n - k + 1) / 2
    ll xSum = onlyX * (2 * n - onlyX + 1) / 2;

    // Assign smallest `onlyY` numbers to y-multiples → 1, 2, ..., onlyY
    ll ySum = onlyY * (onlyY + 1) / 2;

    cout << xSum - ySum << endl;
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
