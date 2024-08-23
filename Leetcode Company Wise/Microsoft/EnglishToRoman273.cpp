// intuiton and approach - 

// Just store the english numbers for 1 - 19 and all the tens. 
// Now simply calculate for last three digits again and again , and put thousands , million , billions according to which part of digits we are considering. Like for last 3 digits nothing is used , then for next 3 digits we will use thousands and so on.




class Solution {
public:
    string helper(int n) {
        vector<string> units = {"One",       "Two",      "Three",   "Four",
                                "Five",      "Six",      "Seven",   "Eight",
                                "Nine",      "Ten",      "Eleven",  "Twelve",
                                "Thirteen",  "Fourteen", "Fifteen", "Sixteen",
                                "Seventeen", "Eighteen", "Nineteen"};

        vector<string> tens = {"Twenty", "Thirty",  "Forty",  "Fifty",
                               "Sixty",  "Seventy", "Eighty", "Ninety"};

        string ans = "";

        if(n/100 > 0){
            ans += units[n/100 - 1] + " Hundred";
            n%=100;

            if(n>0) ans += " ";
        }

        if(n> 0 && n < 20){
            ans += units[n - 1];
        }
        else if( n >= 20){
            ans += tens[n/10 - 2];
            n%=10;
            if(n > 0) ans += " " + units[n - 1];
        }
        return ans;




    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        vector<string> hundreds = {"Thousand", "Million", "Billion"};

        int cnt = -1;
        string ans = "";

        while (num > 0) {
            string curr = helper(num % 1000);
            if (!curr.empty()) {
                if (!ans.empty()) {
                    ans = curr + " " + (cnt >= 0 ? hundreds[cnt] + " " : "") +
                          ans;
                } else {
                    ans = curr + (cnt >= 0 ? " " + hundreds[cnt] : "") + ans;
                }
            }

            cnt++;
            num /= 1000;
        }
        return ans;
    }
};