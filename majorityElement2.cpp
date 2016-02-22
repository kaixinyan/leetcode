vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res; 
        
        // counting occurrence of numbers
        int flag1 = 0;
        int flag2 = 0;
        
        // numbers that are currently counted
        int value1, value2;
        
        int twoMaj = true; //there are two major elements

        
        
        // find two values appearing most of the time
        for(int i = 0; i < nums.size(); i++){

            if(flag1 != 0 && value1 == nums[i]){
                flag1++;
            }
            else if(flag2 != 0 && value2 == nums[i]){
                flag2++;
            }
            else if(!flag1){  // whenever flag1 is zero, 
                value1 = nums[i]; // re-record value1
                flag1++;
            }
            else if(!flag2){
                value2 = nums[i];
                flag2++;
            }
            else{
                flag1--;
                flag2--;
            }
        }

            if(!flag1 && !flag2){
                return {};
            }
            if(!flag2)
                twoMaj = false;

            flag1 = 0, flag2 = 0;

        // counting occurrence of value1 and value2
        for(int i = 0; i < nums.size(); i++){ 
            if(nums[i] == value1)
                flag1++;
            if(twoMaj && nums[i] == value2)
                flag2++;

        }


        if(flag1 > nums.size() / 3) res.push_back(value1);
        if(flag2 > nums.size() / 3) res.push_back(value2);


        return res;
        
    }
