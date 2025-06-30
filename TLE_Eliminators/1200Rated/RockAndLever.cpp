#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define vvl vector<vector<ll>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (ll)(x.size())
#define vin(arr,n) for(ll i = 1; i<=n; i++) cin >> arr[i];
#define vout(arr,n) for(ll i = 1; i<=n; i++) cout << arr[i] << " "; cout << endl;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << #x << " = " << x << endl;
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const ll MAXN = 2e5 + 5;

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

// Factorials for nCr calculations
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

// Sieve of Eratosthenes
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

// Get all prime numbers up to n
vl getPrimes(ll n) {
    vector<bool> is_prime = sieve(n);
    vl primes;
    for(ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.pb(i);
        }
    }
    return primes;
}

// Smallest Prime Factor
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

// Binary Search variants
ll lowerBound(vl &arr, ll target) {
    return lower_bound(arr.begin() + 1, arr.end(), target) - arr.begin();
}

ll upperBound(vl &arr, ll target) {
    return upper_bound(arr.begin() + 1, arr.end(), target) - arr.begin();
}

// Binary search on answer
ll binarySearchAnswer(ll left, ll right, function<bool(ll)> check) {
    ll result = -1;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        if(check(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
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

// Fenwick Tree (Binary Indexed Tree)
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

// Segment Tree
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
    void update(ll idx, ll val) {
        update(1, 1, n, idx, val);
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
    ll query(ll l, ll r) {
        return query(1, 1, n, l, r);
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
};

// Disjoint Set Union (DSU)
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

// LCA using Binary Lifting
class LCA {
public:
    vvl up;
    vl depth;
    ll LOG;
    
    LCA(ll n, vvl &adj, ll root = 1) {
        LOG = ceil(log2(n)) + 1;
        up.assign(n + 1, vl(LOG, 0));
        depth.assign(n + 1, 0);
        dfs(root, 0, adj);
        for(ll j = 1; j < LOG; j++) {
            for(ll i = 1; i <= n; i++) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    
    void dfs(ll u, ll p, vvl &adj) {
        up[u][0] = p;
        for(ll v : adj[u]) {
            if(v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, adj);
            }
        }
    }
    
    ll lca(ll u, ll v) {
        if(depth[u] < depth[v]) swap(u, v);
        ll diff = depth[u] - depth[v];
        for(ll i = 0; i < LOG; i++) {
            if((diff >> i) & 1) u = up[u][i];
        }
        if(u == v) return u;
        for(ll i = LOG-1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    
    ll dist(ll u, ll v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

// Coordinate Compression
vl compress(vl &arr) {
    vl vals = arr;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for(auto &x : arr) {
        x = lower_bound(all(vals), x) - vals.begin() + 1;
    }
    return vals;
}

// Graph utilities
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
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(pair<ll,ll> edge : adj[u]) {
            ll v = edge.first;
            ll w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
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

// Cycle detection in undirected graph
bool hasCycle(ll u, ll p, vvl &adj, vector<bool> &visited) {
    visited[u] = true;
    for(ll v : adj[u]) {
        if(v == p) continue;
        if(visited[v] || hasCycle(v, u, adj, visited)) {
            return true;
        }
    }
    return false;
}

// Utility functions
ll ceilDiv(ll a, ll b) { return (a + b - 1) / b; }
ll floorDiv(ll a, ll b) { return a / b; }
bool isPowerOf2(ll n) { return n > 0 && (n & (n - 1)) == 0; }
ll countSetBits(ll n) { return __builtin_popcountll(n); }

void solve(){
    ll n;
    cin >> n;
    vl arr(n+1);
    vin(arr, n);
    ll ans = 0; unordered_set<ll>st;

    for(ll i = 31; i>=0; i--){
      ll cnt = 0;
      for(ll j = 1; j<=n; j++){
        if(st.find(j) != st.end()) continue;
        if((arr[j] >> i)&1 ) {
          cnt++; st.insert(j);
        }
      }
      ans = ans + ((cnt)*(cnt-1))/2;
    }
    cout << ans << endl;

    

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