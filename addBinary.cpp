string addBinary(string a, string b) {
        
        int la = a.size();
        int lb = b.size();
        
        // make two strings have equal lengths by adding leading 0's
        
        if (la < lb) {
            for (int i = 0; i < lb - la; ++i){
                a = '0' + a;
            }
        }
        
        if (la > lb){
            for (int i = 0; i < la - lb; ++i){
                b = '0' + b;
            }
        }
        
        int l = a.size();
        
        string ans;
        
        int carry = 0;
        
        for (int i = l - 1; i >= 0; --i){
            
            int aBit = a.at(i) - '0';
            int bBit = b.at(i) - '0';
 
          // boolean expression for sum of 3 bits
            int sum = (aBit ^ bBit ^ carry) + '0';
 
            ans = (char)sum + ans;
 
        // boolean expression for 3-bit addition
           carry = (aBit & bBit) | (aBit & carry) | (bBit & carry);
        }
        
        // concatenation: '1' + '0' = '10', '0' + '1' = '01'
        if (carry == 1) ans = '1' + ans;
        
        return ans;
