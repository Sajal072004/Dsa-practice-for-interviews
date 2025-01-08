class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int oneDayCost = costs[0] + solve(i + 1, days, costs, dp);

        int sevenDayCost = costs[1] + solve(
            lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin(),
            days, costs, dp
        );

        int thirtyDayCost = costs[2] + solve(
            lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin(),
            days, costs, dp
        );

        dp[i] = min({oneDayCost, sevenDayCost, thirtyDayCost});

        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1); 
        return solve(0, days, costs, dp); 
    }
};
