vector<int> sum;

    NumArray(vector<int> &nums) {
        
        int n = nums.size();
        
        // in case n = 0
        sum = vector<int>(n+1,0);
        
        
        
        
        for (int i = 0; i < n; ++i){
            sum[i+1] = sum[i] + nums[i];
        }
        
    }
    
    // main

    int sumRange(int i, int j) {
        
        if (sum.size() == 0) return 0;
        
        return sum[j+1] - sum[i];
        
        
    }
