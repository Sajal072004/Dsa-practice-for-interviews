// approach - make a start and ending index. Now keep adding the element and count until its occuring for first time , and if its appearing again , start removing from the beginning and update count. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int st = 0, e = 0;
        int ans = 0, curr = 0;

        while (e < s.size()) {
            if (mp[s[e]] == 0) {
                mp[s[e]]++;
                curr++;
                ans = max(ans, curr);
                e++;
            } else {
                mp[s[st]]--;
                curr--;
                st++;
            }
        }
        return ans;
    }
};
