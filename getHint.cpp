string getHint(string secret, string guess) {
        
        const int digital_num = 10;
        int secret_stat[digital_num] = {0};
        
        int bull = 0;
        for(int i = 0; i < secret.size(); i++) {
            //both number & location are matched, count bull
            if ( secret[i] == guess[i] ) {
                bull++;
                continue;
            }
            //otherwise, count the unmatched digits.
            secret_stat[secret[i]-'0']++; // secret_stat[j] is the times of digit j in string secret unmatching  
        }                                 // digit at the same position in string guess
        
        int cow = 0;
        for(int i = 0; i < guess.size(); i++) {
            //deal with duplication - decrease the digits count if cow is found.
            if ( secret[i] != guess[i] && secret_stat[guess[i]-'0'] > 0 ) {
                secret_stat[guess[i] - '0']--;
                cow++;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B"; // to_string converts numerical value to string
    }
