int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int r = obstacleGrid.size();
        
        if (r == 0) return 0;
        
        int c = obstacleGrid[0].size();
        
        vector<vector<int>> a(r, vector<int>(c));
        
        for (int i = 0; i < r; ++i){
            if (obstacleGrid[i][0] == 1){
                for (int j = i; j < r; ++j)
                    a[j][0] = 0;
                    break;
            }
            else a[i][0] = 1;
            
        }
        
        
        
        for (int j = 0; j <= c; ++j){
            if (obstacleGrid[0][j] == 1) {
                for (int i = j; i < c; ++i)
                    a[0][i] = 0;
                    break;
            }
            else a[0][j] = 1;
        }
        
        for (int i = 1; i < r; ++i){
            for (int j = 1; j < c; ++j){
                if (obstacleGrid[i][j] == 0) a[i][j] = a[i-1][j] + a[i][j-1];
                else a[i][j] = 0;
            }
        }
        
        return a[r-1][c-1];
        
    }
