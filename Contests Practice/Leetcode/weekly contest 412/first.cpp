class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i] , i});
        }

        for(int i = 0; i<k; i++){
            auto x = pq.top(); pq.pop();
            int ind = x.second;
            int val = x.first;
            val = val* multiplier;
            pq.push({val , ind});
        }

        while(!pq.empty()){
            auto x = pq.top(); pq.pop();
            int ind = x.second;
            nums[ind] = x.first;
        }
        return nums;
    }
};