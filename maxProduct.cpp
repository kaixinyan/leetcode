int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        //if (n == 0) return 0;
        //if (n == 1) return nums[0];
        
        int curMax = nums[0];
        int curMin = nums[0];
        int maxP = nums[0];
        
        for (int i = 1; i < n; ++i){
            int temp = curMax;
            curMax = max(nums[i], max(nums[i]*curMax, nums[i]*curMin));
            curMin = min(nums[i], min(nums[i]*temp, nums[i]*curMin));
            maxP = max(maxP,curMax);
            
        }
        
        return maxP;
