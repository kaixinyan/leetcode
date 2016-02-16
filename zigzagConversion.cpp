string convert(string s, int numRows) {
        
        if (numRows <= 1) return s;
        
        int n = s.size();
        
        string ans;
    
        for (int i = 0; i < numRows; ++i){
            for (int j = 0, index = i; index < n; ++j, index = i + j*(2*numRows - 2) ){
                ans += s[index]; // major columns
                if (i == 0 || i == numRows - 1) continue;
                if (index + (2*(numRows-i) - 2) < n)
                   ans += s[index + (2*(numRows-i) - 2)]; // minor columns
            }
        }
        
        return ans;
        
        
    }
