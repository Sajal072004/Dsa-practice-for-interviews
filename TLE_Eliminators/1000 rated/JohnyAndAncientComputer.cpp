#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;


pair<ll, int> get_odd_and_exp(ll n) {
    int exp = 0;
    while (n % 2 == 0) {
        n /= 2;
        exp++;
    }
    return {n, exp};
}

void solve() {
    ll a, b;
    cin >> a >> b;

    pair<ll, int> pa = get_odd_and_exp(a);
    pair<ll, int> pb = get_odd_and_exp(b);

    ll ra = pa.first;
    int exp_a = pa.second;

    ll rb = pb.first;
    int exp_b = pb.second;
    if (ra != rb) {
        cout << -1 << endl;
        return;
    }

    int diff = abs(exp_a - exp_b);
    int ops = 0;

    ops += diff / 3;
    diff %= 3;
    ops += diff / 2;
    diff %= 2;
    ops += diff;

    cout << ops << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
