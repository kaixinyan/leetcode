//
//  main.cpp
//  Pascal's_triangle1
//  Given numRows, generate the first numRows of Pascal's triangle.
//  For example, given numRows = 5,
//  Return
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
//
//  Created by Xingye Kan on 4/5/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;


vector<vector<int> > generate(int numRows) {
    
    vector< vector<int> > triangle;
    
    if (numRows <= 0) {
        triangle.clear();
    }
    
    if (numRows == 1) {
        triangle.push_back({1});
    }
    
    if (numRows == 2) {
        triangle.push_back({1});
        triangle.push_back({1,1});
    }
    
    if (numRows > 2) {
        triangle.push_back({1});
        vector<int> row0 = {1};
        row0.push_back(1);
        triangle.push_back(row0);
        row0.push_back(0);
        vector<int> row1;
        row1.push_back(1);
        for (int rid = 2; rid < numRows; rid++) {
            for (int cid = 0; cid < rid; cid++) {
                row1.push_back(row0[cid] + row0[cid+1]) ;
            }
            
            triangle.push_back(row1);
            row0 = row1;
            row1.clear();
            row1.push_back(1);
            row0.push_back(0);
        }
        
        
    }
    
    
    
    
    return triangle;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int dim = 5;
    
   vector<vector<int> > result = generate(dim);
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}
