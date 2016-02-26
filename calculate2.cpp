int calculate(string s) {
        
        vector<int> parenthesis;  // a vector can be treated as a stack
        
        int result = 0; 
        int sign = 1;
        int num = 0;
        parenthesis.push_back(1);
        
        
        for (int iter = 0; iter < s.length(); iter++){
            if (s[iter] == ' '){
               continue;
            }
        
            if (isdigit(s[iter])){
                num = num * 10 + s[iter] - '0';
                continue;
            }
            
            if (s[iter] == ')'){
                result = result + num * sign * parenthesis.back();
                num = 0;
                parenthesis.pop_back();
                continue;
            }
            
            if (s[iter] == '+'){
               result = result + num * sign * parenthesis.back();
               sign = 1;
               num = 0;
               continue;
            }
            if (s[iter] == '-'){
               result = result + num * sign * parenthesis.back();
               sign = -1;  // sign indicates '+' or '-'
               num = 0;
               continue;
            }
            if (s[iter] == '('){
               result = result + num * sign * parenthesis.back();
               signs.push_back(sign * parenthesis.back());   // each 1 in parenthesis corresponds to a '('
               sign = 1;
               num = 0;
               continue;
            }

         }
        
        result = result + num * sign * parenthesis.back();
        return result;

        
    }
