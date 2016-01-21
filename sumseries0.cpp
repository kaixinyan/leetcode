//
//  main.cpp
//  sumseries0
//  trivial sum problem, search problem indeed
//  Given an array of integers(entries might be repeating), find the number that equals a specific target number.
//
//  return the indice of all elements that are equal to the target number, if no such element exists, return []
//
//  Created by Xingye Kan on 4/10/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumseries0(vector<int> &num, int target){
    
    long int length = num.size();
    
    vector<int> solution;
    
    if (length <= 0) return solution;
    
    for (int i = 0; i < length; i++) {  // the scope of i is only with in for loop
        if (num[i] == target) {
            solution.push_back(i);
        }
    }
    
//    {
//        int i = 0;
//        
//        while (i < length) {
//            if (num[i] == target) {
//                solution.push_back(i);
//            }
//            i++;
//        }
//    }
    
    return solution;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
     vector<int> numbers = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    
    
    vector<int> result;
    
    result = sumseries0(numbers, 2);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
