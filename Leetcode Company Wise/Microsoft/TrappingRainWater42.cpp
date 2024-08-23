// Approach - 

// Just keep the track of largest tile from left and right , now while calculating the answer we know that the maximum height of water can be the minimum of (left , right). Now we just have to subtract the current height from the maximum height.


class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n); vector<int>right(n);
        left[0] = arr[0];
        for(int i = 1; i<n; i++) left[i] = max(left[i-1] , arr[i]);
        right[n-1] = arr[n-1];
        for(int i = n-2; i>= 0; i--){
            right[i] = max(right[i+1] , arr[i]);
        }

        int ans = 0; 
        for(int i = 0; i<n; i++){
            ans += min(left[i] , right[i]) - arr[i];
        }
        return ans;
    }
};