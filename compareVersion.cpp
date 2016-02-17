int compareVersion(string version1, string version2) {
        
        int idx1 = 0, idx2 = 0;
        while(1)
        {
            int v1 = 0, v2 = 0;

            
            // version1[idx1] != '\0', i.e., version1 hasn't been scanned through
            while(version1[idx1] && version1[idx1] != '.')
                v1 += v1*10 + version1[idx1++] - '0';

            while(version2[idx2] && version2[idx2] != '.')
                v2 += v2*10 + version2[idx2++] - '0';

            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
            
            
            // version1[idx1] == '\0', i.e., version1 has been scanned through
            if(!version1[idx1] && !version2[idx2]) return 0;
            if(version1[idx1]) idx1++;
            if(version2[idx2]) idx2++;
        }

        return 0;
