int minimumTotal(vector<vector<int>>& triangle) {
        
        int r = triangle.size();
        
        if (r == 0) return 0;
        
        vector<int> sum = triangle[r-1];
        
        for (int i = r - 2; i >= 0; --i){
            for (int j = 0; j <= i; ++j){
                sum[j] = min(sum[j], sum[j+1]) + triangle[i][j];
            }
        }
        
        return sum[0];
        
        
    }
