#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    ll n, s;
    cin >> n >> s;
    vl arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll totalSum = accumulate(arr.begin(), arr.end(), 0LL);
    if(totalSum < s) {
        cout << -1 << '\n';
        return;
    }
    if(totalSum == s) {
        cout << 0 << '\n';
        return;
    }

    
    ll l = 0, currSum = 0, maxLen = 0;
    for(ll r = 0; r < n; r++) {
        currSum += arr[r];
        while(currSum > s) {
            currSum -= arr[l++];
        }
        if(currSum == s) {
            maxLen = max(maxLen, r - l + 1);
        }
    }

    cout << n - maxLen << '\n'; 
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
