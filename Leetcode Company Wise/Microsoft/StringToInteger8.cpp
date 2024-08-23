// approach - just clear the whitespaces and keep adding to answer , if its exceeding INT_MAX just return int max or min according to sign


class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;
        int i = 0; 
        while(s[i] == ' ') i++;
        if(i >= s.size()) return 0;

        int sign = 1;
        if(s[i] == '-' || s[i] == '+'){
            sign =  s[i] == '+' ? 1 : -1;
            i++;
        }
        
        if(i>=s.size()) return 0;

        int ans = 0;
        for( ;  i<s.size() && s[i] >= '0' && s[i] <= '9'; i++ ){
            if(ans > INT_MAX/10 || ( ans == INT_MAX/10 && s[i] - '0' > INT_MAX%10) ){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans*10 + (s[i] - '0');
        }
        return ans*sign;
    }
};