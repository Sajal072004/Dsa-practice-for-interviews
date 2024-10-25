#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vvi arr(n, vi(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = 0;

        // Loop through all possible submatrices
        for (int size = 1; size <= n; size++) { // Size of the square submatrix
            for (int i = 0; i <= n - size; i++) { // Starting row of submatrix
                for (int j = 0; j <= n - size; j++) { // Starting column of submatrix
                    // Check the main diagonal of the submatrix
                    for (int k = 0; k < size; k++) {
                        if (arr[i + k][j + k] < 0) {
                            ans += abs(arr[i + k][j + k]); // Add how many times we need to increment
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
