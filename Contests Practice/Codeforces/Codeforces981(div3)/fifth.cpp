#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    map<int, int> idxMap;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        idxMap[arr[i]] = i;
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
            if (arr[arr[i]] == i) continue;
            else {
                int j = idxMap[i];
                idxMap[arr[j]] = arr[i];
                idxMap[arr[arr[i]]] = j;
                swap(arr[arr[i]], arr[j]);
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
