//
//  main.cpp
//  combinationSum3
//
//  Created by Xingye Kan on 6/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



void combinationSum(vector<int> candidates, int n, int k, vector<int> &combo, vector<vector<int>> &result, int begin) {
    if (combo.size() == k && n == 0){
        result.push_back(combo);
        return;
    }
    
    for (int i = begin; i < 9 && n >= candidates[i] && combo.size() <= k; ++i){
        combo.push_back(candidates[i]);
        combinationSum(candidates,n-candidates[i],k,combo,result,i+1);
        combo.pop_back();
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates = {1,2,3,4,5,6,7,8,9};
    vector<int> combo;
    vector<vector<int>> result;
    if(k > 9) return result;
    combinationSum(candidates,n,k,combo,result,0);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //int n = 6;
    //int k = 2;
    
    vector<vector<int>> result;
    
    result = combinationSum3(2, 6);
    
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size();j++)
        {
            cout <<  result[i][j];
        }
        cout << ';';
        cout << endl;
    }

    return 0;
}
