class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0; long long maxi = 0;
        for(int i = 0; i<nums.size()-1; i++){
            maxi = max(maxi , (long long)(nums[i]));
            ans += maxi;
        }
        return ans;
    }
};