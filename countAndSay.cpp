//
//  main.cpp
//  countAndSay
//
//  Created by Xingye Kan on 8/3/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    
    string ans;
    
    if(n == 0) return ans;
    
    if(n == 1) {
        ans = "1";
        return ans;
    }
    
    
    string temp;
    
    
    
    ans = "1";
    
    //temp = "1";
    
    
    while(n > 1){
        
        
        int i = 1;
        int count = 1;
        
        char cur = ans[i-1];
        
        if(i == ans.size()){
            temp = temp + to_string(count) + cur;
            ans = temp;
        }
        else{                                // while can be replaced by if else
            
            while (i < ans.size()) {
                if (cur == ans[i]) {
                    ++i;
                    ++count;
                }
                else {
                    temp = temp + to_string(count) + cur;
                    ++i;
                    cur = ans[i-1];
                    count = 1;
                }
            }
            temp = temp + to_string(count) + cur;
            ans = temp;
         }
        
        --n;
        temp.clear();
    }
    
    return ans;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string seq = countAndSay(5);
    std::cout << seq;
    return 0;
}
