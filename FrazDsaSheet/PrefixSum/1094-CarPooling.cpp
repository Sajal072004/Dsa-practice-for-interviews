class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int curr = 0;
        for (auto it : trips) {
            int from = it[1];
            int to = it[2];
            int x = it[0];
            if (!pq.empty() && pq.top().first <= from) {
                curr -= pq.top().second;
                pq.pop();
            }
            curr += x;
            pq.push({to, x});
            if (curr > capacity)
                return false;
        }
        return true;
    }
};