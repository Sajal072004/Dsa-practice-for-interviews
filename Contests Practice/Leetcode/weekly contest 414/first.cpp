class Solution {
public:
    string convertDateToBinary(string date) {
        string year = "";
        for(int i = 0; i<4; i++) year += date[i];
        string month = "";
        for(int i = 5; i<7; i++) month += date[i];
        string day = "";
        for(int i = 8; i<10; i++) day += date[i];

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        string y1 = "";
        while(y>0){
            if(y&1) y1 = '1' + y1;
            else y1 = '0' + y1;
            y = y>>1;
        }
        string m1 = "";
        while(m > 0){
            if(m&1) m1 = '1' + m1;
            else m1 = '0' + m1;
           m = m>>1;
        }
        string d1 = "";
        while(d>0){
            if(d&1) d1 = '1'+ d1;
            else d1 = '0' + d1;
            d = d>>1;
        }

        return (y1 + '-' + m1 + '-' + d1);
        
    }
};