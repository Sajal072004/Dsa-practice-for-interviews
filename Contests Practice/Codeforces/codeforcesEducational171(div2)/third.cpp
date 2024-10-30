#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<int> a, b;
        int c = 0;
        ll ans = 0;
        for (int i = n - 1, j = n; i >= 0; i--, j--) {
            if (s[i] == '1') {
                a.insert(j);
                c++;
            } else {
                ans += j;
                if (c > 0) c--;
            }
        }
        int it = 0;
        int lim = (c + 1) / 2;
        for (auto i : a) {
            if (it == lim) break;
            it++;
            ans += i;
        }
        cout << ans << '\n';
    }
}
