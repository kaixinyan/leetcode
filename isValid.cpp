bool isValid(string s) {
        
        stack<char> st;
        
        
        for (auto ch : s) {
            if (ch == '{' || ch == '[' || ch == '(' ) {
               st.push(ch);
            }
            else if (ch == '}' || ch == ']' || ch == ')' )
            {
                 if (st.empty()) return false; // encounter '}', ']' or ')' first
                 char sch = st.top();
                 if ( (sch == '{' && ch == '}') || (sch == '[' && ch == ']') || (sch == '(' && ch == ')' ) )
                 {
                    st.pop();
                 }
                 else {
                        return false;
                      }
            }
            else {
                   return false;
                 }
        }
       
        return st.empty();
        
    }
