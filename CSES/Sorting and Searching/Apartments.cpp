#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ap(m);   
    for (int i = 0; i < m; i++) cin >> ap[i];

    sort(arr.begin(), arr.end()); 
    sort(ap.begin(), ap.end());   

    int i = 0, j = 0, ans = 0;

    while (i < n && j < m) {
        if (abs(arr[i] - ap[j]) <= k) { 
            ans++; 
            i++;
            j++;  
        } else if (arr[i] < ap[j] - k) {
            i++; 
        } else {
            j++;
        }
    }

    cout << ans << endl; 
}
