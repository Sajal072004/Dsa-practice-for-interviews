class Solution {
public:
    bool solve(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];
        if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            if (j + 1 < p.size() && p[j + 1] == '*') {

                return dp[i][j] = solve(i, j + 2, s, p, dp) ||
                                  solve(i + 1, j, s, p, dp);
            } else {

                return dp[i][j] = solve(i + 1, j + 1, s, p, dp);
            }
        } else {
            if (j + 1 < p.size() && p[j + 1] == '*') {

                return dp[i][j] = solve(i, j + 2, s, p, dp);
            } else {
                return dp[i][j] = false;
            }
        }
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};
