//
//  main.cpp
//  combinationSum

//  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

//  The same repeated number may be chosen from C unlimited number of times.

//  Note:
//  All numbers (including target) will be positive integers.
//  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//  The solution set must not contain duplicate combinations.
//  For example, given candidate set 2,3,6,7 and target 7,
//  A solution set is:
//  [7]
//  [2, 2, 3]



//
//  Created by Xingye Kan on 5/18/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int> candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
    if  (!target) {
        res.push_back(combination);
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], res, combination, i);
        combination.pop_back();
    }
}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }



//void backtrack(vector<int>& candidates, vector<int>& temp, int target, vector<vector<int>>& solution){
//    
//    //vector<int> temp;
//    
//    //vector<vector<int>> solution;
//    
//    if (target == 0) {
//        solution.push_back(temp);
//        return;
//    }
//    
//    for (int i = 0; i < candidates.size() && candidates[i] <= target; i++) {
//        temp.push_back(candidates[i]);
//        backtrack(candidates, temp, target - candidates[i], solution);
//        temp.pop_back();
//        
//
//    }
//    return;
//    
//}
//
//
//
//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//    
//    
//    vector<vector<int>> solution;
//    
//    
//    sort(candidates.begin(), candidates.end());
//    
//    vector<int> temp;
//    
//   backtrack(candidates, temp, target, solution);
//    
//    return solution;
//    
//}



int main(int argc, const char * argv[]) {
    // insert code here...
    int target = 7;
    vector<int> candidates = {2,3,6,7};
    
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
