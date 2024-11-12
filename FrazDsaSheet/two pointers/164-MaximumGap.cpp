class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int bucketSize = max(1, (maxi - mini) / (n - 1));
        int bucketCount = (maxi - mini) / bucketSize + 1;

        vector<int> maxLimit(bucketCount, INT_MIN);
        vector<int> minLimit(bucketCount, INT_MAX);

        for (auto it : nums) {
            if (it == mini || it == maxi) continue;
            int idx = (it - mini) / bucketSize;
            minLimit[idx] = min(minLimit[idx], it);
            maxLimit[idx] = max(maxLimit[idx], it);
        }

        int ans = 0;
        int prev = mini;
        for (int i = 0; i < bucketCount; i++) {
            if (maxLimit[i] == INT_MIN) continue;
            ans = max(ans, minLimit[i] - prev);
            prev = maxLimit[i];
        }
        ans = max(ans, maxi - prev);

        return ans;
    }
};
