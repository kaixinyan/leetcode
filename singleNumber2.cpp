int singleNumber(vector<int>& nums) {
        
        
        
        int digit[32] = {0};
        
        for (int i = 0; i < 32; i++){
            // for each bit, we count the number of appearance of 1's in the array
            for (int j = 0; j < nums.size(); j++){
               digit[i] += ((nums[j] >> i) & 1); // get the value (0 or 1) at ith bit of nums[j]
            }
        }
    
        int res = 0;
        for (int i = 0; i < 32; i++){
            // if (digit[i] % 3) is not zero, it means the single number has 1 at this bit.
            int d = digit[i] % 3 == 0 ? 0: 1;
            res += (d << i);
        }
        
        return res;
        
    }
