#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<string> substrings;

    for(int i = 0; i < n; i++) {
        string temp = "";
        for(int len = 1; len <= 5 && i + len <= n; len++) {
            temp += s[i + len - 1];
            substrings.insert(temp);
        }
    }

    for(int len = 1; len <= 5; len++) {
        string t(len, 'a');
        while(true) {
            if(substrings.find(t) == substrings.end()) {
                cout << t << '\n';
                return;
            }
            
            int idx = len - 1;
            while(idx >= 0 && t[idx] == 'z') {
                t[idx] = 'a';
                idx--;
            }
            if(idx < 0) break;
            t[idx]++;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
