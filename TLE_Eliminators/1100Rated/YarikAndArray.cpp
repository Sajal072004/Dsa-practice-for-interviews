#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long maxSum = a[0];  
        long long max_ending_here = a[0];
        
        for (int i = 1; i < n; i++) {
            
            bool can_extend = (abs(a[i]) % 2) != (abs(a[i-1]) % 2);
            
            if (can_extend) {
                
                max_ending_here = max((long long)a[i], max_ending_here + a[i]);
            } else {
                
                max_ending_here = a[i];
            }
            
            maxSum = max(maxSum, max_ending_here);
        }
        
        cout << maxSum << "\n";
    }
    
    return 0;
}