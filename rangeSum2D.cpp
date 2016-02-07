vector<vector<int>> sum;

    NumMatrix(vector<vector<int>> &matrix) {
        
        
        int r = matrix.size();
        
        if (r == 0) return;
        
        int c = matrix[0].size();
        
        
        
        sum = vector<vector<int>>(r);
        
        for (int i = 0; i < r; ++i){
            sum[i] = vector<int>(c+1,0);
        }
        
        
        
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                sum[i][j+1] = sum[i][j] + matrix[i][j];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        vector<int> range1D(row2 - row1 + 1);
        
        int sol = 0;
        
        // be careful of index of range1D to avoid runtime error
        
        for (int i = row1; i <= row2; ++i){
            range1D[i-row1] = sum[i][col2+1] - sum[i][col1];
            sol += range1D[i-row1];
        }
        
        return sol;
        
    }
