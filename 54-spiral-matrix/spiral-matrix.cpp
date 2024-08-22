class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;

        int a = 0; int b = n-1; 
        int c = 0; int d = m-1;

        while(a<=b && c<=d){

            for(int i = c; i<=d; i++){
                ans.push_back(matrix[a][i]);
            }
            a++;
            if(a>b) break;
            for(int i = a; i<=b; i++){
                ans.push_back(matrix[i][d]);
            }
            d--;
            if(c>d) break;
            for(int i = d; i>= c; i--){
                ans.push_back(matrix[b][i]);
            }
            b--;
            if(a>b) break;
            for(int i = b; i>= a; i--){
                ans.push_back(matrix[i][c]);
            }
            c++;
            if(c>d) break;
        }
        return ans;


    }
};