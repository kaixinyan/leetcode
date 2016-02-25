bool isIsomorphic(string s, string t) {
        
        const int MAXCHAR = 256; // maximal number of char is 256 (including extended ASCII codes)
        
        char maps[MAXCHAR], mapt[MAXCHAR];
        memset(maps, 0, sizeof(maps));
        memset(mapt, 0, sizeof(mapt));
        
        for(int i = 0; i < s.size(); i++){
            // set up mappings between elements of two strings if no such mapping has been constructed
            if(maps[s[i]] == 0 && mapt[t[i]] == 0){  // in maps[s[i]], s[i] is cast into its ASCII code
                maps[s[i]] = t[i];
                mapt[t[i]] = s[i];
                continue;
            }
            // When scanning future elements between the two, check if they obey the mappings just set up
            if(maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
        
    }
