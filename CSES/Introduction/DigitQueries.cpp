#include <bits/stdc++.h>
using namespace std;

// Custom power function to calculate a^b in O(log b) time
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

long long findDigit(long long N) {
    long long digits = 1;
    long long base = 9;
    while (N - digits * base > 0) {
        N -= digits * base;
        base *= 10;
        digits++;
    }

    long long index = N % digits;
    long long res = power(10, digits - 1) + (N - 1) / digits;

    if (index == 0) return res % 10;
    else return (res / power(10, digits - index)) % 10;
}

int main() {
    long long q;
    cin >> q;
    
    
    for (int i = 0; i < q; i++) {
        long long a;
        cin >> a;
        cout << findDigit(a) << endl;
    }

    return 0;
}
