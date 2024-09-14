class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        int cnt = n / k;
        string result = "";
        
        
        for (int i = 0; i < cnt; ++i) {
            int start = i * k;
            int e = start + k;
            int sum = 0;
            for (int j = start; j < e; ++j) {
                char c = s[j];
                sum += c - 'a';  
            }
            
          
            int curr = sum % 26;
            char hash = 'a' + curr;
            result += hash;
        }
        
        return result;
    }
};
