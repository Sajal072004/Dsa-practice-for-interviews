#include <bits/stdc++.h>
using namespace std;

vector<string> generateGrayCode(int n) {
    vector<string> result;
    int total = 1 << n;  // 2^n
    
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);
        string grayCode = bitset<16>(gray).to_string();
        result.push_back(grayCode.substr(16-n)); 
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> grayCodeSequence = generateGrayCode(n);
    
    // Output the Gray code sequence
    for (const string& code : grayCodeSequence) {
        cout << code << endl;
    }
}
