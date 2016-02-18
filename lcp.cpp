string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        if (n == 0) return "";
        
        
        
        // find the shortest string
        
        string minStr = strs[0];
        
        
        
        for (int i = 1; i < n; ++i){
            if (strs[i].size() < minStr.size()) minStr = strs[i];
        }
        
       
       
       
        
        int minLen = minStr.size();
        
        for (int i = 0; i < n; ++i){
            
            int j = 0;
            
            for (;j < minLen; ++j){
                if (strs[i][j] != minStr[j]) break;
            }
            
            if(j < minLen) minLen = j;
        }
        
        //string ans(minLen,'0');
        
        
        
        //for (int i = 0; i < minLen; ++i){
        //    ans[i] = minStr[i];
        //}
        
        string ans;
        
        for (int i = 0; i < minLen; ++i){
            //ans.push_back(minStr[i]);
            ans.append(minStr, i, 1);
        }
        
        return ans;
        //return minStr.substr(0,minLen);
        
    }
