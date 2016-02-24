uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0;
        
        for(int i = 0; i < 32; i++){ // while(n) doesn't work as in reverse integer
            ans = ans * 2 + n % 2;
            n = n / 2 ;
        }
        
        return ans;
        
    }
