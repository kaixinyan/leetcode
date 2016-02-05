int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int startIndex = 0;
        int endIndex = startIndex;
        
        // currentSum[i] denotes sum of max subarray ending at i (prefix)
        vector<int> currentSum(n);
        
        currentSum[0] = nums[0];
        
        for (int i = 0; i < n - 1; ++i){
            
            if (endIndex == n) break;
            
            if ((currentSum[i] <0 && nums[i+1] < 0) || (currentSum[i] < 0 && nums[i+1] >= 0)) {
                startIndex = endIndex + 1;
                endIndex = startIndex;
                currentSum[i+1] = nums[startIndex];
            }
            
            else {
                currentSum[i+1] = currentSum[i] + nums[i+1];
                ++endIndex;
            }
        }
        
        int max = currentSum[0];
        
        for (int i = 0; i < n; ++i){
           if (max < currentSum[i]) max = currentSum[i]; 
        }
        
        return max;
        
    }
