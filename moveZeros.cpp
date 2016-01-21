void moveZeros(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int count = 0;
        
        int temp;
        
        for (int i = nums.size() - 1; i >= 0; i--){
            if (nums[i] == 0){
                
                for (i != nums.size() - 1 - count; i+1 <= nums.size() - 1 - count; i++){
                    temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
                count++;
            }
            
            
            
            
            
        }
        
        return;
    }
