#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    fio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin() + 1, v.end());

        vector<ll> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + v[i].first;
        }

        vector<int> ans(n + 1);
        ans[v[n].second] = n - 1;

        for (int i = n - 1; i >= 1; i--) {
            if (pref[i] >= v[i + 1].first) {
                ans[v[i].second] = ans[v[i + 1].second];
            } else {
                ans[v[i].second] = i - 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
    }

    return 0;
}
