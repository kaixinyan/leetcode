// store each word as an element in the vector of strings called internal
    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;
        
        while (getline(ss, tok, delimiter)) {
             internal.push_back(tok);
        }
        
        return internal;
    }    
    
    
public:
    bool wordPattern(string pattern, string str) {
        
        unordered_map<char, string> dict_pattern; // char is the key
        unordered_map<string, char> dict_string;  // string is the key
        
        int len = pattern.size();
        vector<string> strs = split(str, ' '); 
        
        if (len != strs.size()) return false;
        
        for(int i = 0; i < len; i++) {
            char ch = pattern[i]; // why use char& ch?
            string s = strs[i];  
            
            if ( dict_pattern.find(ch) == dict_pattern.end() ) { // if char ch cannot be founded in dict_pattern
                dict_pattern[ch] = s;                            // set up the mapping: key ch --> value s
            }
            
            if ( dict_string.find(s) == dict_string.end() ) { // string s cannot be founded in dict_string 
                dict_string[s] = ch;                          // set up the mapping: key s --> value ch
            }
            
            if ( dict_pattern[ch] != s || dict_string[s] != ch ) {
                return false;
            }
            
        }
        return true;
    }
