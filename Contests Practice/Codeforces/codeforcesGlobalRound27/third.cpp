#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> permutation;
    
    
    if (n == 5) {
        permutation = {2, 1, 3, 4, 5};
    } else if (n == 6) {
        permutation = {1, 2, 4, 6, 5, 3};
    } else if (n == 7) {
        permutation = {2, 4, 5, 1, 3, 6, 7};
    } else if (n == 8) {
        permutation = {2, 4, 5, 1, 3, 6, 7, 8};
    } else if (n == 9) {
        permutation = {2, 4, 5, 6, 7, 1, 3, 8, 9};
    } else if (n == 10) {
        permutation = {1, 2, 3, 4, 5, 6, 8, 10, 9, 7};
    } else {
        
        for (int i = 2; i <= n; i += 2) {
            permutation.push_back(i);
        }
        for (int i = 1; i <= n; i += 2) {
            permutation.push_back(i);
        }
    }

    
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
