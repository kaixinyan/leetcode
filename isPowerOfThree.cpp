bool isPowerOfThree(int n) {
        
        if (n <= 0) return false;
        
        while(n != 1){
            if (n % 3 == 1 || n % 3 == 2) return false;
            n = n / 3;
        }
        
        return true;
        
    }