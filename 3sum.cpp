//
//  main.cpp
//  3sum
//  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

//  Note:
//  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//  The solution set must not contain duplicate triplets.
//  For example, given array S = {-1 0 1 2 -1 -4},

//  A solution set is:
//  (-1, 0, 1)
//  (-1, -1, 2)


//  Created by Xingye Kan on 4/9/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


// bad
vector<vector<int> > threeSum(vector<int> &num) {
    
    
    vector<vector<int> > solution;
    
    
    if (num.size() < 3) {
        
        return solution;
    }
    
    vector<int> A;
    
    sort(num.begin(),num.end());
    
    
    int i = 0;
    int j = i+1;
    long int k = num.size()-1;
    
    while (i < k) {
        if (num[i] + num[j] + num[k] < 0) {
            j++;
            
        }
        if (num[i] + num[j] + num[k] > 0) {
            k--;
        }
        
        if (num[i] + num[j] + num[k] == 0 && j < k) {
            if (solution.size() == 0 || (solution.size() >0 && !(solution[solution.size()-1][0] == num[i] &&   solution[solution.size()-1][1] == num[j] && solution[solution.size()-1][2] == num[k]))) {
            
                A.push_back(num[i]);
                A.push_back(num[j]);
                A.push_back(num[k]);
                solution.push_back(A);
            }
//            if (find(solution.begin(), solution.end(), A) == solution.end()) {
//               A.push_back(num[i]);
//               A.push_back(num[j]);
//               A.push_back(num[k]);
//            
//               solution.push_back(A);
//            }
            
            j++;
            k--;
            
        }
        
       
        
        
        
        if (j >= k) {
            i++;
            k = num.size() - 1;
            while(i < k && (solution.size() > 0 && num[i] == A[0])) {
                i++;
            }
            j = i + 1;
        }
        A.clear();
    }
    
    
    
    return solution;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> num = {-9,14,-7,-8,9,1,-10,-8,13,12,6,9,3,-3,-15,-15,1,8,-7,-4,-6,8,2,-10,8,11,-15,3,0,-11,-1,-1,10,0,6,5,-14,3,12,-15,-7,-5,9,11,-1,1,3,-15,-5,11,-12,-4,-4,-2,-6,-10,-6,-6,0,2,-9,14,-14,-14,-9,-1,-2,-7,-12,-13,-15,-4,-3,1,14,3,-12,3,3,-10,-9,-1,-7,3,12,-6,0,13,4,-15,0,2,6,1,3,13,8,-13,13,11,11,13,14,-6};
    
    //vector<int > num = {0,1,1};
    
    vector<vector<int> > result = threeSum(num);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << result.size() << endl;
    return 0;
}
