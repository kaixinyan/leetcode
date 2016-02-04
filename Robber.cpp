nt rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 0) return 0;
        
        if (n == 1) return nums[0];
        
        vector<int> value(n);
        
        value[0] = nums[0];
        value[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        
        for (int i = 0; i < n - 2; ++i){
            value[i+2] = value[i+1] > value[i] + nums[i+2] ? value[i+1] : value[i] + nums[i+2];
        }
        
        return value[n-1];
        
        
       
        
        
        
        
        
        
        
    }
