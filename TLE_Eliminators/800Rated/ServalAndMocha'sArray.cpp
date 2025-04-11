#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vin(arr, n) for (int i = 0; i < n; i++) cin >> arr[i];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

bool canBeBeautiful(const vector<ll>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(a[i], a[j]) <= 2) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vin(a, n);

        cout << (canBeBeautiful(a) ? "Yes" : "No") << '\n';
    }

    return 0;
}
