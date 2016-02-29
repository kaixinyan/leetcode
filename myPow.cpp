double myPow(double x, int n) {
        
        bool sign = false;
        unsigned int exp = n;
        
        if (n < 0){
           exp = -n;
           sign = true;
        }
        double result = 1.0;
        while (exp) {
              if (exp & 1){ // exp is an odd number
                 result *= x;
              }
              exp = exp >> 1;
              x *= x;
        }

        return sign ? 1/result : result;
        
    }
