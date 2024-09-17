#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        vector<long long> first, second;
        long long target = sum / 2;
        
        
        for (long long i = n; i >= 1; --i) {
            if (target >= i) {
                first.push_back(i);
                target -= i;
            } else {
                second.push_back(i);
            }
        }

        
        cout << first.size() << endl;
        for (long long x : first) {
            cout << x << " ";
        }
        cout << endl;

        
        cout << second.size() << endl;
        for (long long x : second) {
            cout << x << " ";
        }
        cout << endl;
    }
}
