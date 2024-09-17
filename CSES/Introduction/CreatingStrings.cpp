#include <bits/stdc++.h>
using namespace std;


void generatePermutations(string s) {
    
    sort(s.begin(), s.end());
    set<string> permutations;

    do {
        permutations.insert(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << permutations.size() << endl;
    for (const auto& p : permutations) {
        cout << p << endl;
    }
}

int main() {
    string s;
    cin >> s;

    generatePermutations(s);
    
    return 0;
}
