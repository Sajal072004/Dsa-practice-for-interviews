class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        map<char,int>mp1; int cnt = 1;
        for(char c = '1'; c<='8'; c++) mp1[c] = cnt++;
        map<char,int>mp2; cnt=1;
        for(char c = 'a'; c<='h'; c++) mp2[c] = cnt++;

        char first = coordinate1[0]; char second = coordinate1[1];
        char third = coordinate2[0]; char fourth = coordinate2[1];

        int a = mp2[first] + mp1[second];
        int b = mp2[third] + mp1[fourth];

        if((a%2) == (b%2)) return true;
        return false;
    }
};