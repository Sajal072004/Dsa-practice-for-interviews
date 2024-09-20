#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> prices; 
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.insert(price);
    }

    vector<int> customer(m);
    for (int i = 0; i < m; i++) {
        cin >> customer[i];
    }

    vector<int> ans(m, -1);

    for (int i = 0; i < m; i++) {
        int budget = customer[i];
        auto it = prices.upper_bound(budget);
        
        if (it != prices.begin()) {
            --it; 
            ans[i] = *it;
            prices.erase(it);  
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}
