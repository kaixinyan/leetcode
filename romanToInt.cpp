int romanToInt(string s) {
        
        int n = s.size();
        
        if (n == 0) return 0;
        
        int ans = 0;
        
        char pre;
        
        for (int i = 0; i < n; ++i){
            if (s[i] == 'M' && pre != 'C') ans += 1000;
            
            if (s[i] == 'M' && pre == 'C') ans += 900 - 100;
              
            if (s[i] == 'D' && pre != 'C') ans += 500;
            
            if (s[i] == 'D' && pre == 'C') ans += 400 - 100;
            
            if (s[i] == 'C' && pre != 'X') ans += 100;
            
            if (s[i] == 'C' && pre == 'X') ans += 90 - 10;
            
            if (s[i] == 'L' && pre != 'X') ans += 50;
            
            if (s[i] == 'L' && pre == 'X') ans += 40 - 10;
            
            if (s[i] == 'X' && pre != 'I') ans += 10;
            
            if (s[i] == 'X' && pre == 'I') ans += 9 - 1;
        
            if (s[i] == 'V' && pre != 'I') ans += 5;
            
            if (s[i] == 'V' && pre == 'I') ans += 4 - 1;
            
            if (s[i] == 'I') ans += 1;
            
            pre = s[i];
            
            
        }
        
        return ans;
        
        
    }
