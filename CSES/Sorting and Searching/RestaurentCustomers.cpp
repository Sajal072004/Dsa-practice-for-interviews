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

int main() {
    int n; 
    cin >> n;
    vpii arr(n); 
    vpin(arr, n);
    sort(arr.begin(), arr.end());
    
    int ans = 0;   
    priority_queue<int, vector<int>, greater<int>> endTimes;

    for (int j = 0; j < n; j++) {
        while (!endTimes.empty() && endTimes.top() < arr[j].first) {
            endTimes.pop();
        }
        
        endTimes.push(arr[j].second);
        ans = max(ans, (int)endTimes.size());
    }

    cout << ans << endl; 
}
