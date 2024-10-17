class Solution {
public:

    int solve(int i , int j , string s){
        if(i > j) return 0;
        while(i>=0 && j < s.size() && s[i] == s[j]){
            i--; j++;
        }
        return j - i - 1;
    }


    string longestPalindrome(string s) {
        int start = 0; int end = 0;
        for(int i = 0; i<s.size(); i++){
            int maxi = max(solve(i , i , s) , solve(i , i+1 , s));

            if(maxi > end - start){
                start = i- (maxi-1)/2;
                end = i + maxi/2;
            }
        }
        return s.substr(start , end-start+1);
    }
};