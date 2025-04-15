#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getMaxConsecutiveCount(const vector<int>& arr) {
    unordered_map<int, int> countMap;
    int count = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            countMap[arr[i - 1]] = max(countMap[arr[i - 1]], count);
            count = 1;
        }
    }

    // Update for the last element's sequence
    countMap[arr[arr.size() - 1]] = max(countMap[arr[arr.size() - 1]], count);

    return countMap[arr[arr.size() - 1]];
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int, int> maxA, maxB;

    // Count max streaks in array A
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) count++;
        else {
            maxA[a[i - 1]] = max(maxA[a[i - 1]], count);
            count = 1;
        }
    }
    maxA[a[n - 1]] = max(maxA[a[n - 1]], count);

    // Count max streaks in array B
    count = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i - 1]) count++;
        else {
            maxB[b[i - 1]] = max(maxB[b[i - 1]], count);
            count = 1;
        }
    }
    maxB[b[n - 1]] = max(maxB[b[n - 1]], count);

    int maxLength = 0;

    // Check max total streak for each value
    for (int value = 1; value <= 2 * n; value++) {
        int total = 0;
        if (maxA.find(value) != maxA.end()) total += maxA[value];
        if (maxB.find(value) != maxB.end()) total += maxB[value];
        maxLength = max(maxLength, total);
    }

    cout << maxLength << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
