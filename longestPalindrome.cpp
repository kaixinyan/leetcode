string findPalindrome(string s, int left, int right){
        
        // 1. time limit exeeds "abb"
        // while (left >= 0 && right <= s.size() - 1){
        //     if (s[left] == s[right]){
        //        --left;
        //        ++right;
        //     }
        //}
        
        // 2. working
        // while (left >= 0 && right <= s.size() - 1){
        //     if (s[left] != s[right]) break;
             
        //     else{
        //        --left;
        //        ++right;
        //     }
        // }
        
        // 3. optimal
        while (left >= 0 && right <= s.size() - 1 && s[left] == s[right]){
                --left;
                ++right;
        }
        
        return s.substr(left + 1,right - left - 1);
        
    }




    string longestPalindrome(string s) {
        
        if (s.size() <= 1) return s;
        
        string ans;
        
        string str;
        
        for (int i = 0; i < s.size() - 1; ++i){
            // Step to generate odd length palindrome:
            // Fix a centre and expand in both directions for longer palindromes.
            str = findPalindrome(s, i, i);
            if (str.size() > ans.size()) ans = str;
            
            // Step to generate even length palindrome
            // Fix two centre ( low and high ) and expand in both directions for longer palindromes.
            str = findPalindrome(s,i,i+1);
            if (str.size() > ans.size()) ans = str;
        }
        
        return ans;
        
        
        
    }
