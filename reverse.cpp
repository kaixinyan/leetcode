int reverse(int x) {
        
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10; // over/underflow must occur here if any
            
            if (temp / 10 != ans) return 0; // if occurres, operation (temp - x % 10) / 10 = temp / 10 = ans is not reversable
                                            // Warning: (temp - x % 10) / 10 might not equal to temp / 10 - (x % 10) / 10
                                            // but temp / 10 - (x % 10) / 10 equals temp / 10 since (x % 10) is 0
            
            ans = temp;
            x /= 10;
        }
        return ans;
    }
