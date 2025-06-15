#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vl vector<long long>
#define vpii vector<pair<ll,ll>>
#define vpll vector<pair<ll,ll>>
#define vvi vector<vector<ll>>
#define vvl vector<vector<long long>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (ll)(x.size())
#define vin(arr,n) for(ll i = 1; i<=n; i++) cin >> arr[i];
#define vout(arr,n) for(ll i = 1; i<=n; i++) cout << arr[i] << " "; cout << endl;
#define voutn(arr,n) for(ll i = 1; i<=n; i++) cout << arr[i] << (i==n ? "\n" : " ");
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vpin(arr,n) for(ll i = 1; i<=n; i++){ cin >> arr[i].first; cin >> arr[i].second; }
#define pq priority_queue<ll,vector<ll>,greater<ll>>
#define pqm priority_queue<ll>
#define ppq priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>
#define ppqmax priority_queue<pair<ll,ll>>
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const double EPS = 1e-9;
const ll MAXN = 2e5 + 5;
const double PI = acos(-1.0);

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod = MOD) { return power(a, mod - 2, mod); }

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vl fact, invfact;
void precomputeFactorials(ll n, ll mod = MOD) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for(ll i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[n] = modInverse(fact[n], mod);
    for(ll i = n-1; i >= 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }
}

ll nCr(ll n, ll r, ll mod = MOD) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invfact[r] % mod) * invfact[n-r] % mod;
}

ll nPr(ll n, ll r, ll mod = MOD) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invfact[n-r]) % mod;
}

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vl spf;
void smallestPrimeFactor(ll n) {
    spf.resize(n + 1);
    for(ll i = 1; i <= n; i++) spf[i] = i;
    for(ll i = 2; i * i <= n; i++) {
        if(spf[i] == i) {
            for(ll j = i * i; j <= n; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

map<ll, ll> primeFactors(ll n) {
    map<ll, ll> factors;
    while(n > 1) {
        ll p = spf[n];
        factors[p]++;
        n /= p;
    }
    return factors;
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

ll lowerBound(vl &arr, ll target) {
    return lower_bound(arr.begin() + 1, arr.end(), target) - arr.begin();
}

ll upperBound(vl &arr, ll target) {
    return upper_bound(arr.begin() + 1, arr.end(), target) - arr.begin();
}

bool isPowerOf2(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

ll floorDiv(ll a, ll b) {
    return a / b;
}

ll countSetBits(ll n) {
    return __builtin_popcountll(n);
}

ll msb(ll n) {
    return 63 - __builtin_clzll(n);
}

ll lsb(ll n) {
    return __builtin_ctzll(n);
}

// Prefix sum for 1-based indexing
class PrefixSum {
public:
    vl pref;
    PrefixSum(vl &arr) {
        ll n = sz(arr) - 1;
        pref.resize(n + 2, 0);
        for(ll i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + arr[i];
        }
    }
    ll query(ll l, ll r) {
        return pref[r] - pref[l-1];
    }
};

// 2D Prefix sum for 1-based indexing
class PrefixSum2D {
public:
    vvl pref;
    PrefixSum2D(vvl &arr) {
        ll n = sz(arr) - 1;
        ll m = sz(arr[1]) - 1;
        pref.assign(n + 2, vl(m + 2, 0));
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= m; j++) {
                pref[i][j] = arr[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
    }
    ll query(ll r1, ll c1, ll r2, ll c2) {
        return pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
    }
};

// Fenwick Tree (Binary Indexed Tree) for 1-based indexing
class FenwickTree {
public:
    vl tree;
    ll n;
    FenwickTree(ll size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    void update(ll idx, ll val) {
        for(; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    ll query(ll idx) {
        ll sum = 0;
        for(; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
    ll rangeQuery(ll l, ll r) {
        return query(r) - query(l-1);
    }
};

// Segment Tree for 1-based indexing
class SegmentTree {
public:
    vl tree;
    ll n;
    SegmentTree(vl &arr) {
        n = sz(arr) - 1;
        tree.resize(4 * n + 1);
        build(arr, 1, 1, n);
    }
    void build(vl &arr, ll node, ll start, ll end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            ll mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    void update(ll node, ll start, ll end, ll idx, ll val) {
        if(start == end) {
            tree[node] = val;
        } else {
            ll mid = (start + end) / 2;
            if(idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        if(r < start || end < l) {
            return 0;
        }
        if(l <= start && end <= r) {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll p1 = query(2*node, start, mid, l, r);
        ll p2 = query(2*node+1, mid+1, end, l, r);
        return p1 + p2;
    }
    void update(ll idx, ll val) {
        update(1, 1, n, idx, val);
    }
    ll query(ll l, ll r) {
        return query(1, 1, n, l, r);
    }
};

// Lazy Propagation Segment Tree
class LazySegmentTree {
public:
    vl tree, lazy;
    ll n;
    LazySegmentTree(ll size) {
        n = size;
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }
    void push(ll node, ll start, ll end) {
        if(lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if(start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(ll node, ll start, ll end, ll l, ll r, ll val) {
        push(node, start, end);
        if(start > r || end < l) return;
        if(start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        ll mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        push(2*node, start, mid);
        push(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        if(start > r || end < l) return 0;
        push(node, start, end);
        if(start >= l && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
    void updateRange(ll l, ll r, ll val) {
        updateRange(1, 1, n, l, r, val);
    }
    ll query(ll l, ll r) {
        return query(1, 1, n, l, r);
    }
};

// Disjoint Set Union (DSU) with 1-based indexing
class DSU {
public:
    vl parent, size;
    DSU(ll n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(ll i = 1; i <= n; i++) parent[i] = i;
    }
    ll find(ll x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(ll x, ll y) {
        ll px = find(x), py = find(y);
        if(px == py) return false;
        if(size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
        return true;
    }
    bool connected(ll x, ll y) {
        return find(x) == find(y);
    }
    ll getSize(ll x) {
        return size[find(x)];
    }
};

// Matrix operations
vvl multiply(vvl &A, vvl &B, ll mod = MOD) {
    ll n = sz(A), m = sz(B[0]), p = sz(B);
    vvl C(n, vl(m, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            for(ll k = 0; k < p; k++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return C;
}

vvl matrixPower(vvl mat, ll p, ll mod = MOD) {
    ll n = sz(mat);
    vvl result(n, vl(n, 0));
    for(ll i = 0; i < n; i++) result[i][i] = 1;
    while(p > 0) {
        if(p & 1) result = multiply(result, mat, mod);
        mat = multiply(mat, mat, mod);
        p >>= 1;
    }
    return result;
}

// Fibonacci using matrix exponentiation
ll fibonacci(ll n, ll mod = MOD) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    vvl base = {{1, 1}, {1, 0}};
    vvl result = matrixPower(base, n-1, mod);
    return result[0][0];
}

// String utilities
bool isPalindrome(string s) {
    ll n = sz(s);
    for(ll i = 0; i < n/2; i++) {
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

vl computeLPS(string pattern) {
    ll m = sz(pattern);
    vl lps(m, 0);
    ll len = 0, i = 1;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len-1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

vl KMPSearch(string text, string pattern) {
    vl result;
    vl lps = computeLPS(pattern);
    ll n = sz(text), m = sz(pattern);
    ll i = 0, j = 0;
    while(i < n) {
        if(pattern[j] == text[i]) {
            i++; j++;
        }
        if(j == m) {
            result.pb(i - j + 1); // 1-based indexing
            j = lps[j-1];
        } else if(i < n && pattern[j] != text[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return result;
}

// Polynomial Hashing
class PolynomialHash {
public:
    vl hash, pow;
    ll base, mod;
    PolynomialHash(string s, ll b = 31, ll m = 1e9 + 9) {
        base = b; mod = m;
        ll n = sz(s);
        hash.resize(n + 1, 0);
        pow.resize(n + 1, 1);
        for(ll i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + (s[i] - 'a' + 1)) % mod;
            pow[i + 1] = (pow[i] * base) % mod;
        }
    }
    ll getHash(ll l, ll r) { // 1-based indexing
        ll result = hash[r] - hash[l - 1] * pow[r - l + 1] % mod;
        return (result % mod + mod) % mod;
    }
};

ll rangeGCD(const vector<ll>& a,ll start = 1, ll k = 1) {
    ll result = a[0];
    for (ll i = start; i < a.size(); i += k) {
        result = gcd(result, a[i]);
    }
    return result;
}

// Graph utilities for 1-based indexing
void dfs(ll u, vvl &adj, vector<bool> &visited) {
    visited[u] = true;
    for(ll v : adj[u]) {
        if(!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

vl dijkstra(ll src, ll n, vector<vpll> &adj) {
    vl dist(n + 1, INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
    dist[src] = 0;
    que.push({0, src});
    while(!que.empty()) {
        ll d = que.top().fi;
        ll u = que.top().se;
        que.pop();
        if(d > dist[u]) continue;
        for(auto edge : adj[u]) {
            ll v = edge.fi;
            ll w = edge.se;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

bool bellmanFord(ll src, ll n, vector<array<ll,3>> &edges, vl &dist) {
    dist.assign(n + 1, INF);
    dist[src] = 0;
    for(ll i = 0; i < n - 1; i++) {
        for(auto e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(auto e : edges) {
        ll u = e[0], v = e[1], w = e[2];
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            return false; // negative cycle
        }
    }
    return true;
}

vvl floydWarshall(ll n, vvl &adj) {
    vvl dist = adj;
    for(ll k = 1; k <= n; k++) {
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

// Topological Sort
vl topologicalSort(ll n, vvl &adj) {
    vl indegree(n + 1, 0);
    for(ll u = 1; u <= n; u++) {
        for(ll v : adj[u]) {
            indegree[v]++;
        }
    }
    queue<ll> q;
    for(ll i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vl result;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        result.pb(u);
        for(ll v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return result;
}

void solve(){
    ll n;
    cin >> n;
    vl arr(n+1);
    vin(arr, n);

    ll odd  = rangeGCD(arr,1,2);
    ll even = rangeGCD(arr,2,2);

    bool flag = true;
    for(ll i = 1; i<=n; i+=2){
        if((arr[i]%even) == 0){
            flag = false; break;
        }
    }
    if(flag){
        cout << even << endl; return;
    }

    flag = true;
    for(ll i = 2; i<=n; i+=2){
        if((arr[i]%odd) == 0){
            flag = false; break;
        }
    }
    if(flag) cout << odd << endl;
    else cout<< 0 << endl;




    


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