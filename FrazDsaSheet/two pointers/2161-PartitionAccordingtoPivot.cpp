//brute force

class Solution
{
public:
  vector<int> pivotArray(vector<int> &nums, int pivot)
  {
    vector<int> left;
    vector<int> right;
    vector<int> p;
    for (auto it : nums)
    {
      if (it < pivot)
        left.push_back(it);
      if (it > pivot)
        right.push_back(it);
      if (it == pivot)
        p.push_back(it);
    }
    vector<int> ans;
    for (auto it : left)
      ans.push_back(it);
    for (auto it : p)
      ans.push_back(it);
    for (auto it : right)
      ans.push_back(it);
    return ans;
  }
};

//optimised

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lessCount = 0, equalCount = 0;

      
        for (int num : nums) {
            if (num < pivot) lessCount++;
            else if (num == pivot) equalCount++;
        }

        // Create the result vector with the correct size
        vector<int> ans(nums.size());
        int leftIndex = 0, midIndex = lessCount, rightIndex = lessCount + equalCount;

        // Place elements in the appropriate positions
        for (int num : nums) {
            if (num < pivot) {
                ans[leftIndex++] = num;
            } else if (num == pivot) {
                ans[midIndex++] = num;
            } else {
                ans[rightIndex++] = num;
            }
        }

        return ans;
    }
};
