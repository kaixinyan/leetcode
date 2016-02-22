void setZeroes(vector<vector<int>>& matrix) {
        
        // bRow or bCol is the flag indicating whether first row or column contains 0 or not
        int bRow = false, bCol = false;
        
        
        // projecting zeros in the matrix onto first row and column
        // i.e. if m[i][j] is zero, set m[0][j] and m[i][0] to be zeroes
        // also record whether first row or column should be zero
        for (int r = 0; r < matrix.size(); r++){
            for (int c = 0; c < matrix[r].size(); c++){
                if (matrix[r][c] == 0){
                    if (r == 0) bRow = true;
                    if (c == 0) bCol = true;
                    matrix[0][c] = matrix[r][0] = 0;
                }
            }
        }
        
        // setting element in matrix from the second row and column to be zero 
        // according to corresponding elements in the first row and column
        for (int r = 1; r < matrix.size(); r++){
            for (int c = 1; c < matrix[r].size(); c++){
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        
        
        // handling first row and column according to flag bRow and bCol
        if (bRow){
            for(int c = 0; c < matrix[0].size(); c++) matrix[0][c] = 0;
        }
        if (bCol){
            for(int r = 0; r < matrix.size(); r++) matrix[r][0] = 0;
        }
        
        
    }
