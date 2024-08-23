


class Solution {
  public:
   
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int>in(n,0); vector<int>out(n,0);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                out[i] += mat[i][j];
                in[j] += mat[i][j];
            }
        }
        
        for(int i = 0; i<n; i++){
            if( in[i] == n-1 && out[i] == 0) return i;
        }
        return -1;
        
    }
};