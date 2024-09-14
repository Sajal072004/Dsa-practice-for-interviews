class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        
        for(int len = 2; len <= n; len++) {
            for(int st = 0; st + len - 1 < n; st++) {
                int end = st + len - 1;
                dp[st][end] = dp[st][end-1] ^ dp[st+1][end]; 
            }   
        }

        for(int len = 2; len <= n; len++) {
            for(int st = 0; st + len - 1 < n; st++) {
                int end = st + len - 1;
                dp[st][end] = max({dp[st][end], dp[st][end-1], dp[st+1][end]});
            }
        }

        vector<int> res;
        for(vector<int>& quer: queries) {
            int u = quer[0], v = quer[1];
            res.push_back(dp[u][v]);
        }

        return res;
    }
};