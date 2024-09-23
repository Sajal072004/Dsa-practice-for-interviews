#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define vin(arr,n) for(int i = 0; i<n; i++) cin >> arr[i];
#define vout(arr) for(auto x : arr) cout << x << " ";
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    fast_io
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n; 
        vl wealth(n);
        
        vin(wealth, n); 
        ll total = 0;
        
        if (n == 1 || n == 2) {
            cout << -1 << '\n';
            continue;
        }

        for (ll w : wealth) total += w;
        sort(all(wealth)); 

        ll md = wealth[n / 2]; 
        cout << max(0ll, (2 * md * n) - total + 1) << '\n';
    }
    return 0;1
}
