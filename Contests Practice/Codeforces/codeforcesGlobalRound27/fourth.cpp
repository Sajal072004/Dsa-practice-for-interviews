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
#define vpin(arr,n) for(int i = 0; i<n; i++){ cin >> arr[i].first; cin >> arr[i].second; }

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// GCD function (Euclidean algorithm)
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// LCM function
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Power function (modular exponentiation)
ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

// Check if a number is prime
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Factorial function with modulo
ll factorial(ll n, ll mod = MOD) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}

// nCr (combinations) function using Fermat's Little Theorem
ll modInverse(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod); // Fermat's Little Theorem for mod inverse
}

ll nCr(ll n, ll r, ll mod = MOD) {
    if (r > n) return 0;
    ll num = factorial(n, mod);
    ll denom = (factorial(r, mod) * factorial(n - r, mod)) % mod;
    return (num * modInverse(denom, mod)) % mod;
}

// Sieve of Eratosthenes to generate primes up to a limit
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Find all divisors of a number
vi divisors(int n) {
    vi divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i != n / i) divs.pb(n / i);
        }
    }
    sort(all(divs));
    return divs;
}

// Binary search for a specific condition
int binarySearch(vi &arr, int target) {
    int low = 0, high = sz(arr) - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Target not found
}


ll solve(vl arr, int j, vl highest, vl prefixSum, vl subtract , vl operations) {


    ll maxi = highest[j] % MOD; ll temp = 0; ll opCount = operations[j];
    if(maxi%2 == 0){
      ll x = maxi;
      while(x%2 == 0) {
        temp += x/2; x/=2; opCount --;
      }
    }

    ll ans = (prefixSum[j] % MOD - subtract[j]%MOD + temp%MOD - maxi%MOD)%MOD;

    ans = ans + (maxi * pow(2,opCount));

    return ans;



}

int main() {
    ll t; 
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vl arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        vl highest(n);
        highest[0] = arr[0] % MOD;
        for (ll i = 1; i < n; i++) {
            highest[i] = max(arr[i], highest[i - 1]) % MOD;
        }

       

        vl prefixSum(n);
        prefixSum[0] = arr[0] % MOD;
        for (ll i = 1; i < n; i++) {
            prefixSum[i] = (arr[i] + prefixSum[i - 1]) % MOD;
        }

        vl subtract(n,0);  vl operations(n,0);
        ll sub = 0;
        for (ll i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                ll x = arr[i];
                while (x % 2 == 0) {
                    sub = (sub + x / 2) % MOD;
                    x /= 2;
                }
            }
            subtract[i] = sub % MOD;
        }

        for(ll i = 0; i<n; i++){
         if(i>0) operations[i] = operations[i-1];
         ll x = arr[i];
          while(x % 2 == 0){
            x /= 2; operations[i]++;
          }
        }


       
        for (ll j = 0; j < n; j++) {
            cout << solve(arr, j, highest, prefixSum, subtract, operations) << " ";
        }
        cout << endl;

        // cout << solve(arr, 0, highest, prefixSum, subtract, operations) << endl;

        cout << "highest array is" << endl;
        vout(highest);
        cout << endl;

        cout << "prefix array is" << endl;
        vout(prefixSum);
        cout << endl;

        cout << "subtract is" << endl;
        vout(subtract);
        cout << endl;

        cout << "operations is" << endl;
        vout(operations);
        cout << endl;
    }
}
