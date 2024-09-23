#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define vin(arr, n)           \
  for (int i = 0; i < n; i++) \
    cin >> arr[i];
#define vout(arr)    \
  for (auto x : arr) \
    cout << x << " ";
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define vpin(arr, n)          \
  for (int i = 0; i < n; i++) \
  {                           \
    cin >> arr[i].first;      \
    cin >> arr[i].second;     \
  }

const int MOD = 1e9 + 7;
const ll INF = 1e18;


int main() {
    fast_io;

    int t; 
    cin >> t;
    
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        
        vi start(n + 1, 0);
        vi end(n + 1, 0);
        
        
        for (int i = 0; i < k; i++) {
            int l, r;
            cin >> l >> r;
            start[l]++;
            end[r]--;
        }
        
        int curr = 0;
        
        
        for (int i = 1; i <= d; i++) {
            curr += start[i];
        }
        
        int maxLeaves = curr;
        int minLeaves = curr;
        int maxIndex = 1;
        int minIndex = 1;
        
       
        for (int i = d + 1; i <= n; i++) {
            curr += start[i];        
            curr += end[i - d];     
            
            
            if (curr > maxLeaves) {
                maxLeaves = curr;
                maxIndex = i - d + 1;
            }
            
           
            if (curr < minLeaves) {
                minLeaves = curr;
                minIndex = i - d + 1;
            }
        }
        
        
        cout << maxIndex << ' ' << minIndex << '\n';
    }

    return 0;
}
