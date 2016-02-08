int uniquePaths(int m, int n) {
        
        if (m*n == 0) return 0;
        
        vector<vector<int>> a(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i){
            a[i][0] = 1;
        }
        
        for (int j = 0; j < n; ++j){
            a[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                a[i][j] = a[i][j-1] + a[i-1][j];
            }
        }
        
        return a[m-1][n-1];
        
    }
