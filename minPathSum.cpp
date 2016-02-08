int minPathSum(vector<vector<int>>& grid) {
        
        int r = grid.size();
        
        if (r == 0) return 0;
        
        int c = grid[0].size();
        
        vector<vector<int>> sum(r,vector<int>(c));
        
        sum[0][0] = grid[0][0];
        
        for (int i = 0; i < r - 1; ++i){
            sum[i+1][0] = sum[i][0] + grid[i+1][0];
        }
        
        for (int j = 0; j < c - 1; ++j){
            sum[0][j+1] = sum[0][j] + grid[0][j+1];
        }
        
        for (int i = 1; i < r; ++i){
            for (int j = 1; j < c; ++j){
                sum[i][j] = min(sum[i][j-1] + grid[i][j], sum[i-1][j] + grid[i][j]);
            }
        }
        
        return sum[r-1][c-1];
        
    }
