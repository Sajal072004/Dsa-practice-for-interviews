#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve( ll n , vector<ll>arr){
    if(n%2 == 0) {
            ll maxi = 0;
            for (int i = 1; i < n; i += 2) {
                maxi = max(maxi, arr[i] - arr[i - 1]);
            }
            cout << maxi << '\n';
        }

        else {
            ll res = LLONG_MAX;
            for (int i = 1; i < n; i++) {
                if (i % 2 == 1)
                    arr.insert(arr.begin() + i, arr[i - 1] + 1);
                else
                    arr.insert(arr.begin() + i, arr[i] - 1);

                ll maxi = 0;
                for (int j = 1; j <= n; j += 2) {
                    maxi = max(maxi, arr[j] - arr[j - 1]);
                }
                res = min(res, maxi);
                arr.erase(arr.begin() + i);
            }
            cout << res << '\n';
        } 
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        solve(n , arr);

       
    }
}
