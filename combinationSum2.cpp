//
//  main.cpp
//  combinationSum2
//
//  Created by Xingye Kan on 6/12/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void combinationSum(vector<int> candidates, int target, vector<int> &combo, vector<vector<int>> &result, int begin){
    if (target == 0)
    {result.push_back(combo);
        return;}
    
    for(int i = begin; i < candidates.size() && target >= candidates[i]; ++i){
        
        combo.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], combo, result, i+1);
        combo.pop_back();
        
        while (candidates[i] == candidates[i+1]) {
            ++i;
        }
    }
    
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> combo;
    vector<vector<int>> result;
    

     combinationSum(candidates,target,combo,result,0);
    return(result);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int target = 8;
    vector<int> candidates = {10,1,2,7,6,1,5};
    
    vector<vector<int>> result;
    
    result = combinationSum(candidates, target);
    
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
