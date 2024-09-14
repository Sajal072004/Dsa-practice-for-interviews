class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        string str3 = to_string(num3);
        
        
        while (str1.length() < 4) str1 = '0' + str1;
        while (str2.length() < 4) str2 = '0' + str2;
        while (str3.length() < 4) str3 = '0' + str3;
        
       
        string key = "";
        
       
        for (int i = 0; i < 4; ++i) {
            char mini = min({str1[i], str2[i], str3[i]});
            key += mini;
        }
        
        
        return stoi(key);
    }
};
