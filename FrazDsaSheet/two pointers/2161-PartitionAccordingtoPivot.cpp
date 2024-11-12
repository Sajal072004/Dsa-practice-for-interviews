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