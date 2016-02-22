bool isUgly(int num) {
        
        if (num <= 0) return 0;
        
        if (num == 1) return 1;
        
        int factor[3] = {2, 3, 5};
        
        
        int quo = num;
        
        for (int i = 0; i < 3; i++){
        
            while (quo % factor[i] == 0){
                  quo = quo / factor[i];
            }
            
            if (quo == 1) return 1;
        
        }
        
        
        
        
       return 0;
        
        
        
    }
