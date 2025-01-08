class Solution
{
public:
  int solve(int i, int j, vector<int> piles, int last,
            vector<vector<int>> &dp)
  {
    if (i >= j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (last == 0)
    {
      return dp[i][j] = max(solve(i + 1, j, piles, 1, dp) + piles[i],
                            piles[j] + solve(i, j - 1, piles, 1, dp));
    }
    return dp[i][j] = max(-piles[i] + solve(i + 1, j, piles, 0, dp),
                          -piles[j] + solve(i, j - 1, piles, 0, dp));
  }
  bool stoneGame(vector<int> &piles)
  {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solve(0, piles.size() - 1, piles, 0, dp);
    return ans > 0;
  }
};