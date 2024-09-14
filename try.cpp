#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long crazySubarrays(int n, int k, vector<int>& arr) {
    unordered_map<int, int> mp; // Frequency map to store occurrences of elements
    int i = 0; // Left pointer of the sliding window
    long long ans = 0; // To store the count of crazy subarrays
    
    for (int j = 0; j < n; j++) {
        // Add the current element to the frequency map
        mp[arr[j]]++;
        
        // Shrink the window from the left until it becomes a crazy subarray
        bool flag = false;
        while (i <= j) {
            for (auto& it : mp) {
                if (it.second >= k) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) break;
            
            
            mp[arr[i]]--;
            if (mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        }
        
        // Count the number of crazy subarrays that end at 'j'
        ans += (j - i + 1);
    }
    
    return ans;
}

int main() {
    int n = 5, k = 3;
    vector<int> arr = {4, 4, 4, 1, 4};
    
    cout << crazySubarrays(n, k, arr) << endl; // Expected output: 4
    return 0;
}
