string strPlus(string& num1, string& num2) {
            if (num1.size() == 0) return num2;
            if (num2.size() == 0) return num1;

            if ( num1.size() < num2.size() ) {
                swap(num1, num2);
            }

            string s;
            int carry = 0;
            int x;
            for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0; i--, j--) {
                x = num1[i] - '0' + carry;
                if(j >= 0){
                    x += num2[j] - '0';
                }
                s.insert(s.begin(), x%10 + '0');
                carry = x/10;
            }
            if (carry) {
                s.insert(s.begin(), carry + '0');
            }

            return s;
        }






    string multiply(string num1, string num2) {
        
        if (num1.size() <= 0 || num2.size() <= 0) return "";

        string result;
        for ( int i = num1.size() - 1; i >= 0; i--) {
                
            int carry = 0;
                
            string val;
                
            // every digit of string 1 is multiplied with every digit of string 2 and store result from each round into val
            // first round i = num1.size() - 1: right most digit of string 1 multiply every digit of string 2
            // second round i = num1.size() - 2: second from right digit of string 1 multiply .....
            for( int j = num2.size() - 1; j >= 0; j--) {
                int v = (num2[j] - '0') * (num1[i] - '0') + carry; // convert char into int
                    
                val.insert(val.begin(), v%10 + '0'); // convert int into char and store the result one by one to val from                                       front
                carry = v/10;
            }
            
            if (carry) val.insert(val.begin(), carry + '0'); // last carry
                
                
              
            // first round i = num1.size() - 1: shift val to left by 0 position
            // second round i = num1.size() - 1: shift val to left by 1 position
            for (int j = i; j < num1.size() - 1; j++) {
                val.push_back('0');
            }
            
            // accumulating multiplication from each round
            result = strPlus(result, val);
        }

        //check if it is zero
        if (result[0]=='0') return "0";
        return result;
        
    }
