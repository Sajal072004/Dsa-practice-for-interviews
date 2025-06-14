#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, r = n - 1;
    int suml = a[0], sumr = a[n - 1];
    int ans = 0;

    while (l < r) {
        if (suml == sumr) {
            ans = max(ans, l + 1 + n - r);
        }

        if (suml <= sumr) {
            l++;
            if (l < r) suml += a[l];
        } else {
            r--;
            if (l < r) sumr += a[r];
        }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
