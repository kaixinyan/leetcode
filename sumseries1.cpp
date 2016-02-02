//
//  main.cpp
//  sumseries1
//  Given an array of integers(entries might be repeating), find two numbers whose sum equals a specific target number.

//  1. return the unique pairs of solution in the form {a1, a2}, where a1 <= a2
//  2. return the indices in the form {i1, i2}, where i1 < i2, i1, i2 != 0

//  Created by Xingye Kan on 4/11/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sumseries1(vector<int> num, int target){
    
    
    vector<vector<int>> solution;
    
    vector<int> pair;
    
    long int length = num.size();
    
    if (length <= 1) {
        return solution;
    }
    
    int i = 0;
    int j = length - 1;
    
    
    sort(num.begin(), num.end());
    
    while (i < j) {
        if (num[i] + num[j] < target) {
            i++;
        }
        if (num[i] + num[j] > target) {
            j--;
        }
        if (i >= j) {
            return solution;
        }
        if (num[i] + num[j] == target) {
            pair.push_back(num[i]);
            pair.push_back(num[j]);
            solution.push_back(pair);
            pair.clear();
            i++;
            j--;
            while (i + 1 < j && num[i] == num[i-1]) {
                i++;
            }
            if (i + 1 == j) {
                return solution;
            }
        }
        
    }
    
    
    return solution;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> numbers = {-13, -12, -12, -12, -11, -11, -10, -9, -9, -8, -8, -8, -8, -7, -7, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 14, 14, 14, 14, 14, 14};
    
    //vector<int> numbers = {-4,-4,-2,-1,1,1,3,3,3,3};
    
    
    vector<vector<int>> result;
    
    result = sumseries1(numbers, 2);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < 2; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
