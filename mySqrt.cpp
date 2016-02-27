int mySqrt(int x) {
        
        if (x <= 0 ) return 0;
    
    //the sqrt is not greater than x/2+1 since geometric mean is always <= arithmetic mean
    int high = x/2 + 1;
    int low = 0;
    
    // binary search
    while ( low <= high ) {
        int mid = low + (high - low) / 2; // don't use (low + high)/2 since low + high might overflow
        long long sq = (long long) mid * (long long) mid;
        if (sq == x ) return mid;
        if (sq < x) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return high; 
    }
