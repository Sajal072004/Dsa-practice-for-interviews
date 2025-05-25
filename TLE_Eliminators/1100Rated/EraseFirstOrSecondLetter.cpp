#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<bool> seen(26, false);
    ll result = 0;

    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (!seen[c]) {
            seen[c] = true;
            result += n - i;
        }
    }

    cout << result << '\n';
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
