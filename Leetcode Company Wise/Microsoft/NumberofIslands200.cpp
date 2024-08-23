// approach - 

// Simply push all the 1s in the queue and perform dfs for every index. 
// Just count all the unvisited components.

class Solution {
public:

    void dfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>&grid){
        vis[i][j] = 1;
        vector<int>disr = { -1 , 0 , 1 , 0};
        vector<int>disc = { 0 , 1 , 0 , -1};

        for(int k = 0; k<4; k++){
            int row = i + disr[k];
            int col = j + disc[k];

            if(row >= 0 && col >= 0 && col < grid[0].size() && row < grid.size() && vis[row][col] == 0 && grid[row][col] == '1'){
                dfs(row , col , vis , grid );
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1') q.push({i , j});
            }
        }
        int ans = 0;

        while(!q.empty()){
            auto x = q.front(); q.pop();
            int row = x.first;
            int col = x.second;

            if(vis[row][col] == 0){
                ans ++;
                dfs(row , col , vis , grid);
            }

        }
        return ans;



    }
};