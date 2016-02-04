int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n <= 1) return n;
        
        vector<int> L(n); 
        
        L[0] = 1; // base case
        
        if (nums[0] < nums[1]) L[1] = 1 + L[0];
        else L[1] = 1;
        
        int max = 0;
        
        for (int j = 2; j < n; ++j){
            for (int i = 0; i < j; ++i){
                if (nums[i] < nums[j]){
                   if (max < L[i]) max = L[i];
                }
                //else max = 0;
            }
            L[j] = 1 + max;
            max = 0;
        }
        
        
        int length = 1;
        
        for (int i = 0; i < n - 1; ++i){
            if (length < L[i+1]) length = L[i+1];
        }
        
        
        
        
        
       
        return length;
}
