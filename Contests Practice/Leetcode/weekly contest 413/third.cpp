class Solution {
public:
    int dp[101][1025];
    int solve(int idx,int mask,map<int,vector<int> >&arr){
        if(idx==0){
            return 0;
        }
        
        if(dp[idx][mask] != -1){
            return dp[idx][mask];
        }
        
        int res=solve(idx-1,mask,arr);
        
        for(auto i:arr[idx]){
            if((mask & (1<<i))==0){
                res=max(res,idx+solve(idx-1,mask|(1<<i),arr));
            }
        }
        
        return dp[idx][mask]=res;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        map<int,vector<int> > arr;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[grid[i][j]].push_back(i);
            }
        }
        
        return solve(100,0,arr);
    }
};