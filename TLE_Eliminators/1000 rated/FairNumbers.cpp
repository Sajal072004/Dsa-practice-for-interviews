#include <iostream>
using namespace std;

bool isFair(long long int x) {
    long long int temp = x;
    while (temp > 0) {
        long long int digit = temp % 10;
        if (digit != 0 && x % digit != 0) {
            return false;
        }
        temp /= 10;
    }
    return true;
}

long long int findFairNumber(long long int n) {
    while (!isFair(n)) {
        n++;
    }
    return n;
}

 int main() {
    long long int t;
    cin >> t;
    while(t--){
        long long int n; cin >> n;
        cout << findFairNumber(n) << endl;
    }
    
    return 0;
}
