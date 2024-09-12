class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        int n = queries.size();
        vector<int> result(n, -1);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int distance = abs(x) + abs(y);

            pq.push(distance);
            if (pq.size() > k) {
                pq.pop(); 
            }

            if (pq.size() == k) {
                result[i] = pq.top();
            }
        }

        return result;
    }
};