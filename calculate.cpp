int calculate(string s) {
        
        char op;
        int cur = 0;
        int prev = 0;
        int diff = 0;
        int i = 0;
        
        while (i < s.size()) {
           if (s[i] == ' ') {
              i++;
              continue;
           }
           if (isdigit(s[i])) { // check if s[i] is a decimal digit between '0' to '9'
              cur = 0;  // first digit of each string of digits
              while (i < s.size() && isdigit(s[i])) { // transform first encounted string of digits into an integer
                    cur = cur * 10 + s[i] - '0';      // and store it in cur
                    i++;
              }
              if (op == '\0') {
                  prev = cur;
                  diff = cur;
              }
              else {
                  if (op == '+') {
                      diff = cur;
                      prev = prev + cur;
                  }
                  else if (op == '-') {
                      diff = -cur;
                      prev = prev - cur;
                  }
                  else if (op == '*') {
                      int tmp = diff;
                      diff = diff * cur;
                      prev = prev - tmp + tmp * cur; // if '*' is after '+' of '-', prev - tmp is to subtract previously added                                value
                  }
                  else if (op == '/') {
                      int tmp = diff;
                      diff = diff / cur;
                      prev = prev - tmp + tmp / cur;
                  }
               }
             }
             
           else {
              op = s[i];
              i++;
                }
        }
    return prev;
    }
