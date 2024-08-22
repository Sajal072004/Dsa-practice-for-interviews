// intuition and approach - 

// simply store all the elements in the map with their indexes , now traverse the array and find (target - arr[i]) , if that number exists in the array just return the indexes of both numbers



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp; int n = nums.size();
        for(int i = 0; i<n; i++) mp[nums[i]] = i;
        vector<int>ans(2);

        for(int i = 0; i<n; i++){
            if(mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]] != i ){
                ans[0] = i;
                ans[1] = mp[target-nums[i]];
                break;
            }
        }
        return ans;
    }
};