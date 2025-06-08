#include <bits/stdc++.h>
using namespace std;

bool possible(int n, vector<long long>& a) {
    
    long long d = a[1] - a[0];
    
    long long num = a[0] - d; 
    long long deno = n + 1;
    
    if (num % deno != 0) {
        return false;
    }
    
    long long y = num / deno;
    if (y < 0) {
        return false;
    }
    
    
    long long x = d + y;
    if (x < 0) {
        return false;
    }
    
  
    for (int i = 0; i < n; i++) {
        
        long long pos = i + 1;
        long long curr = pos * d + y * deno;
        if (a[i] != curr) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (possible(n, a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}