int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if (n <= 1) return 0;
        
        vector<int> ans(n,0);
        
        ans[0] = 0;
        
        int low = prices[0];
        //int high = ans[0];
        
        for (int i = 1; i < n; ++i){
            if (prices[i] > low)
               ans[i] = max(ans[i-1], prices[i] - low);
            else {
                low = prices[i];
                ans[i] = ans[i-1];
            }
        }
        
        return ans[n-1];
    }
