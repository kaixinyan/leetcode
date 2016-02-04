int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        
        vector<int> r1(n-1);
        
        r1[0] = nums[0];
        r1[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        
        for (int i = 0; i < n - 3; ++i){
            r1[i+2] = r1[i+1] > r1[i] + nums[i+2] ? r1[i+1] : r1[i] + nums[i+2];
        }
        
        vector<int> r2(n-1);
        
        r2[0] = nums[1];
        r2[1] = nums[1] > nums[2] ? nums[1] : nums[2];
        
        for (int i = 1; i < n - 2; ++i){
            r2[i+1] = r2[i] > r2[i-1] + nums[i+2] ? r2[i] : r2[i-1] + nums[i+2];
        }
        
        return r1[n-2] > r2[n-2] ? r1[n-2] : r2[n-2];
    }
