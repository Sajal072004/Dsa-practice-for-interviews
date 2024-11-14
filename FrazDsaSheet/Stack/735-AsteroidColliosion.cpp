
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            while (!st.empty() && st.top() >= 0 && arr[i] < 0) {
                if (abs(st.top()) < abs(arr[i])) {
                    st.pop();
                } else if (abs(st.top()) == abs(arr[i])) {
                    st.pop();
                    flag = true;
                    break;
                } else {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                st.push(arr[i]);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};