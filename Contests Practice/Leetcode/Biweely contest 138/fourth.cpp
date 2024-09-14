class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int,int>>arr;
        int n = damage.size();
        for(int i = 0; i<n; i++){
            int time = (health[i] + power - 1)/power;
            arr.push_back({damage[i] , time});
        }

        sort(arr.begin(), arr.end() , [](const pair<int,int>&a , const pair<int,int>&b){
            return (a.first*b.second )> (a.second*b.first);
        });

        long long total_damage = 0;
        long long total_time = 0;

        for(int i = 0; i<n; i++){
            int d = arr[i].first;
            int time = arr[i].second;
            total_time +=time;
            total_damage += d*total_time;
        }
        return total_damage;
    }
};