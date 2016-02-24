vector<int> singleNumber(vector<int>& nums) {
        
        int x = 0;
        
        for (int i = 0; i < nums.size(); i++){
            x = x ^ nums[i];
        }
        
        vector<int> ans(2,0);
        
        // From right to left, find the first non-zero bit of binary representation of x
        
        int dif;
        
        for (int i = 0; i < 32; i++){
            
            if ((x >> i) & 1) {
                dif = i;
                break;
            }
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (((nums[i] >> dif) & 1) == 0) ans[0] = ans[0] ^ nums[i];
            else ans[1] = ans[1] ^ nums[i];
        }
        
        return ans;
        
    }
