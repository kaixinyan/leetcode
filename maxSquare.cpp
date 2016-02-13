int maximalSquare(vector<vector<char>>& matrix) {
        
        int r = matrix.size();
        
        if (r == 0) return 0;
        
        int c = matrix[0].size();
        
        vector<vector<int>> sum(r,vector<int>(c));
        
        // base case
        
        
        
        for (int i = 0; i < r; ++i){
            sum[i][0] = matrix[i][0] == '1';
        }
        
        for (int j = 1; j < c; ++j){
            sum[0][j] = matrix[0][j] == '1';
        }
        
        
        
        int maxS = sum[0][0];
        
        for (int i = 1; i < r; ++i){
            if (maxS < sum[i][0]) maxS = sum[i][0];
        }
        
        for (int j = 1; j < c; ++j){
            if (maxS < sum[0][j]) maxS = sum[0][j];
        }
        
        
        int i,j;
        
        for (i = 1; i < r; ++i){
            for (j = 1; j < c; ++j){
                if (matrix[i][j] == '1') {
                    sum[i][j] = min(sum[i-1][j],sum[i][j-1],sum[i-1][j-1]) + 1;
                }
                else sum[i][j] = 0;
                if (sum[i][j] > maxS) maxS = sum[i][j];
            }
            
        }
        
        return maxS*maxS;
    }
    
        int min(int a, int b, int c)
        {
          int m = a;
          if (m > b) m = b;
          if (m > c) m = c;
          return m;
        }
