#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvl vector<vector<ll>>
#define vl vector<ll>

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vvl arr(n, vl(m));

        ll mini = LLONG_MAX;
        ll sum = 0;
        ll negativeCount = 0;

        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> arr[i][j];
                ll val = abs(arr[i][j]);
                sum += val;
                mini = min(mini, val);
                if (arr[i][j] < 0) {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 == 0) {
            cout << sum << endl;
        } else {
            cout << sum - 2 * mini << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    solve();
    return 0;
}
