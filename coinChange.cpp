int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<int> ans(amount+1);
        
        ans[0] = 0;
        
        for (int i = 1; i <= amount; ++i){
            ans[i] = INT_MAX - 1;
        }
        
        for (int i = 1; i <= amount; ++i){
            for (int j = 0; j < n; ++j){
                if (i - coins[j] >= 0){
                    int temp = ans[i-coins[j]];
                    if(temp + 1 < ans[i]) ans[i] = temp + 1;
                }
            }
        }
        
        if (ans[amount] == INT_MAX - 1) return -1;
        
        else return ans[amount];
    }
