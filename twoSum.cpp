//
//  main.cpp
//  twoSum
//


//  Given an array of integers, find two numbers such that they add up to a specific target number.
//
//  The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//  You may assume that each input would have exactly one solution.
//
//  Input: numbers={2, 7, 11, 15}, target=9
//  Output: index1=1, index2=2

//  Created by Xingye Kan on 4/6/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//
//  variation
//  (i) assume the solution might not exist, might not be unique, we only want to keep the same solution once
//  (ii) as in 3sum, return all the unique pair of solutions rather than return indicies

#include <iostream>
#include <vector>
using namespace std;

// brute force
//vector<int> twoSum(vector<int> &numbers, int target) {
//    
//    vector<int> index;
//    int temp;
//    
//    for (int i = 0; i < numbers.size(); i++) {
//        temp = target - numbers[i];
//        
//        for (int j = i + 1; j < numbers.size(); j++) {
//            if (numbers[j] == temp) {
//                index.push_back(i+1);
//                index.push_back(j+1);
//                break;
//            }
//        }
//        index.clear();
//    }
//    return index;
//    
//}


// same problem for sorted array

vector<int> twoSum(vector<int> &numbers, int target) {
    
    vector<int> index;
    
    vector<int> copy = numbers;
    
    sort(copy.begin(), copy.end());
    
    int i = 0;
    
    long int j = copy.size() - 1;
    
    while (i < j) {
        if (copy[i] + copy[j] < target) i++;
        if (copy[i] + copy[j] > target) j--;
        if (copy[i] + copy[j] ==  target) {
            break;
        }
    }

    int id1;
    int id2;
    
    
    for (int k = 0; k < numbers.size(); k++) {
        if (numbers[k] == copy[i]) {
            id1 = k+1;
        }
    }
    
    for (int k = 0; k < numbers.size(); k++) {
        if (numbers[k] == copy[j] && k+1 != id1) {
            id2 = k+1;
        }
    }
    
    
    
    if (id1 < id2) {
        index.push_back(id1);
        index.push_back(id2);
    }
    else {
        index.push_back(id2);
        index.push_back(id1);
    }
    
    
    return index;
}






int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> numbers = {150,24,79,50,88,345,3};
    int target = 200;
    
    vector<int> result = twoSum(numbers, target);
    
    for (int i = 0; i < 2; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
