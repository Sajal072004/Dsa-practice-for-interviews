#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int res = 0, sum = 0, mx = 0;

        for (int i = 0; i < min(n, k); ++i) {
            sum += a[i];
            mx = max(mx, b[i]);
            res = max(res, sum + mx * (k - i - 1));
        }

        cout << res << '\n';
    }
    return 0;
}
