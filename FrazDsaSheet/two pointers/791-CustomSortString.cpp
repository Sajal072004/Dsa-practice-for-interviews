class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        
        string ans = "";
        for (char c : order) {
            if (mp.count(c)) {
                ans += string(mp[c], c); 
                mp.erase(c);
            }
        }
        for (auto& pair : mp) {
            ans += string(pair.second, pair.first);
        }
        
        return ans;
    }
};
