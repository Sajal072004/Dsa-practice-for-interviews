// Approach -

// Expanding every index as middle and counting the size of palindrome, store the start and ending of largest palindrome and return that substring.



class Solution {
public:
    int expand(int left , int right , string&s){
        if(left > right) return 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if(s.size() < 1) return "";
        int start = 0; int end = 0;
        for(int i = 0; i<s.size(); i++){
            int maxi = max( expand(i , i , s) , expand(i , i+1 , s));
            
            if( maxi > end - start){
                start = i - (maxi-1)/2;
                end = i+ (maxi)/2;
            }
        }
        return s.substr(start , end-start +1);
        
    }
};