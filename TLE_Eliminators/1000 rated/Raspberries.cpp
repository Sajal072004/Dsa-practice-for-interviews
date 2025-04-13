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
#define vout(arr) for(auto x : arr) cout << x << " "; cout << endl;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vpin(arr,n) for(int i = 0; i<n; i++){ cin >> arr[i].first; cin >> arr[i].second; }

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
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
ll factorial(ll n, ll mod = MOD) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}
ll modInverse(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }
ll nCr(ll n, ll r, ll mod = MOD) {
    if (r > n) return 0;
    ll num = factorial(n, mod);
    ll denom = (factorial(r, mod) * factorial(n - r, mod)) % mod;
    return (num * modInverse(denom, mod)) % mod;
}
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
vl divisors(ll n) {
    vl divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i != n / i) divs.pb(n / i);
        }
    }
    sort(all(divs));
    return divs;
}
int binarySearch(vi &arr, int target) {
    int low = 0, high = sz(arr) - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

bool isPowerOf2(long long n) {
return n > 0 && (n & (n - 1)) == 0;
}

void solve(){
    ll n,k;
    cin >> n >> k;
    vl arr(n);
    vin(arr, n);
    for(auto it : arr){
      if(it%k == 0){
        cout << 0 << endl;
        return;
      }
    }

    if(k == 2){
      cout << 1 << endl;
      return;
    }
    if(k == 3){
      bool flag = false;
      for(auto it : arr){
        if(it%3 == 2) {
          cout << 1 << endl;
          return;
        }
      }
      cout << 2 << endl; return;
    }

    if(k == 4){
      int cntEven = 0; bool flag = false;
      for(auto it : arr){
        if(it%4 == 3){
          flag = true;
        }
        if(it%2 == 0) cntEven++;
        
      }
      if(cntEven >= 2) cout << 0 << endl;
      else if(flag || cntEven == 1) cout << 1 << endl;
      else cout << 2 << endl;
      return; 
    }

    if(k == 5){
      bool flag1 = false; bool flag2 = false;
      for(auto it : arr){
        if(it%5 == 4){
          cout << 1 << endl;
          return;
        }
        if(it%5 == 3) flag1 = true;
        if(it%5 == 2) flag2 = true;
      }

      if(flag1) cout << 2 << endl;
      else if(flag2) cout << 3 << endl;
      else cout << 4 << endl;
    }


}

int main(){
    fast_io;
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}