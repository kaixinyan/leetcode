// return the sum of squares of each digit of n
    int squares(int n) {
        int result = 0;
        int sq = 0;
        for (; n > 0; n /= 10) {
            sq = n % 10;
            result += (sq * sq);
        }
        return result;
    }



    bool isHappy(int n) {
        if (n == 1) return true;

        map<int, bool> m;
        m[n] = true;

    while (n != 1) {
        n = squares(n);   // keep computing sum of squares until it is 1
        
        if (m.find(n) != m.end()){ // if squares(n) is looping
            return false;
        }
        m[n] = true;
    }

    return true;
        
    }
