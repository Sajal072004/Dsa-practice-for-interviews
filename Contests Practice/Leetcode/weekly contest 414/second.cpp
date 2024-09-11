class Solution {
public:

    bool check(vector<int>&arr , long long ans , int d){
        long long curr = arr[0];
        for(long long i = 1; i<arr.size(); i++){
            if(curr + ans < arr[i]) curr = arr[i];
            else if( curr + ans <= arr[i] + d) curr = curr + ans;
            else return false;
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin() , start.end());
        long long left = 0; 
        long long right = d + start[start.size() - 1] - start[0];
        long long ans = 0;
        long long mid = left + (right-left)/2;
        while(left <= right){
            if(check(start , mid, d)){
                ans = mid;
                left = mid+1;
            }   
            else right = mid-1;
            mid = left + (right-left)/2;
        }
        return ans;

    }
};