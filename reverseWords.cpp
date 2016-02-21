void reverseWords(string &s) {
        
        // reverse the order of all elements from s.begin() to s.end() - 1
        reverse(s.begin(), s.end());
        
        
    int before = 0;
    
    // reverse each word but spaces between words remain
    // ps: if there are no trailing spaces, last word is not reversed
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverse(s.begin() + before, s.begin() + i);
            before = i+1;
        }
    }
    
    // either last word is reversed if there are no trailing spaces
    // or trailing spaces remain
    reverse(s.begin() + before, s.end());
    
    // find out the "essential" length by reducing extra spaces in space
    int slen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            s[slen++] = s[i];
            if (s[i+1] == ' ' || i == s.size()-1)
                s[slen++] = ' ';
        }
    }
    s = s.substr(0, slen == 0 ? 0 : slen-1);
    }
