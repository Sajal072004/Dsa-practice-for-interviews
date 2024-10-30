#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using vl = vector<ll>;

const ll MOD = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll solve(vl &arr, int j) {
    ll currentSum = 0, maxEven = 0, evenSum = 0;

    // Find prefix sum, maximum even, and sum of even numbers for current prefix
    for (int i = 0; i <= j; i++) {
        currentSum = (currentSum + arr[i]) % MOD;
        if (arr[i] % 2 == 0) {
            evenSum = (evenSum + arr[i]) % MOD;
            maxEven = max(maxEven, arr[i]);
        }
    }

    // If there’s a max even number, maximize it
    ll opCount = 0;
    while (maxEven % 2 == 0) {
        maxEven /= 2;
        opCount++;
    }

    // Calculate answer for this prefix
    ll result = (currentSum - evenSum + MOD) % MOD;
    result = (result + (evenSum - maxEven + MOD) % MOD) % MOD;
    result = (result + maxEven * mod_pow(2, opCount, MOD)) % MOD;

    return result;
}

int main() {
    ll t; 
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vl arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        // Process each prefix
        for (ll j = 0; j < n; j++) {
            cout << solve(arr, j) << " ";
        }
        cout << endl;
    }
}
