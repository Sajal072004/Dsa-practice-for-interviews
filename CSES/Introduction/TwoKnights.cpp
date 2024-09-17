#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int k = 1; k <= n; ++k) {
        long long total_ways = (long long)k * k * (k * k - 1) / 2;
        
        long long attack_ways = 0;
        if (k > 2) {
            attack_ways = 4 * (k - 1) * (k - 2);
        }
        
        cout << total_ways - attack_ways << endl;
    }
    
    return 0;
}
