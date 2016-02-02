//
//  main.cpp
//  validPalindrome
//
//  Created by Xingye Kan on 6/1/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

//  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

//  For example,
//  "A man, a plan, a canal: Panama" is a palindrome.
//  "race a car" is not a palindrome.

//  Note:
//  Have you consider that the string might be empty? This is a good question to ask during an interview.

//  For the purpose of this problem, we define empty string as valid palindrome.

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    
    string sp;
    
    if (s.length() <= 1) {
        return true;
    }
    
    
    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) < '0' || (s.at(i) > '9' && s.at(i) < 'A') ||  (s.at(i) > 'Z' && s.at(i) < 'a') || s.at(i) > 'z') {
            continue;
        }
        
        if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
            s.at(i) = s.at(i) + 32;
        }
        sp.push_back(s.at(i));
    }
    
    
    
    while (sp.length() > 1) {
        if (sp[0] == sp[sp.length()-1]) {
            sp.erase(sp.begin());
            sp.pop_back();
        }
        else break;
        
    }
    
    if (sp.length() > 1) {
        return false;
    }
    
    return true;
    
    
    
    
    
    
    

}



int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "......a.....";
    bool result = isPalindrome(s);
    //cout << (int)s[1] << endl;
    //cout << (int)s[2] << endl;
    cout << result << endl;
    return 0;
}
