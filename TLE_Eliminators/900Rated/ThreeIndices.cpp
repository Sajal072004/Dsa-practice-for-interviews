#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    int left_min_index = 0;

    for(int j = 1; j < n - 1; ++j) {
        if(p[left_min_index] < p[j]) {
            for(int k = j + 1; k < n; ++k) {
                if(p[k] < p[j]) {
                    cout << "YES\n";
                    cout << left_min_index + 1 << " " << j + 1 << " " << k + 1 << "\n";
                    return;
                }
            }
        }

        if(p[j] < p[left_min_index]) {
            left_min_index = j;
        }
    }

    cout << "NO\n";
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
