//
//  main.cpp
//  sumseries2
//  Given an array of integers(entries might be repeating), find three numbers whose sum equals a specific target number.

//  1. return the unique triples of solution in the form {a1, a2, a3}, where a1 <= a2 <= a3
//
//  Created by Xingye Kan on 4/14/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sumseries2(vector<int> num, int target){

    vector<vector<int>> solution;
    
    vector<int> triple;
    
    long int length = num.size();
    
    if(length <= 2) return solution;
    
    sort(num.begin(), num.end());

    
    int i = 0;
    int j = i + 1;
    long int k = length - 1;
    
    while (i < k - 1) {
        if (num[i] + num[j] + num[k] < target) {
            j++;
        }
        if (num[i] + num[j] + num[k] > target) {
            k--;
        }
        if (j >= k) {
            i++;
            while (num[i] == num[i-1]) {
                i++;
                
            }
            j = i + 1;
            k = length - 1;
            continue;
        }
        if (num[i] + num[j] + num[k] == target) {
            triple.push_back(num[i]);
            triple.push_back(num[j]);
            triple.push_back(num[k]);
            solution.push_back(triple);
            triple.clear();
            j++;
            k--;
            while (j < k && num[j] == num[j-1]) {
                j++;
            }
            if (j >= k) {
                i++;
                while (num[i] == num[i-1]) {
                    i++;
                    
                }
                j = i + 1;
                k = length - 1;

                
            }
            
        }
        
    }

    return solution;

}





int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> numbers = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    
    
    
    
    
    // vector<int> numbers = {-13, -12, -12, -12, -11, -11, -10, -9, -9, -8, -8, -8, -8, -7, -7, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 14, 14, 14, 14, 14, 14};
    
    
    
    vector<vector<int>> result;
    
    result = sumseries2(numbers, 0);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
