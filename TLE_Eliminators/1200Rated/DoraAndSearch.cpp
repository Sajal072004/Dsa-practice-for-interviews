#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1); // 1-based indexing
    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = n;
    int min_val = 1, max_val = n;

    while (l < r) {
        if (a[l] == min_val || a[l] == max_val) {
            if (a[l] == min_val) min_val++;
            else max_val--;
            l++;
        } else if (a[r] == min_val || a[r] == max_val) {
            if (a[r] == min_val) min_val++;
            else max_val--;
            r--;
        } else {
            cout << l << " " << r << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
