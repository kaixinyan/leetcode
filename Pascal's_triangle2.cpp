//
//  main.cpp
//  Pascal's_triangle2
//  Given an index k, return the kth row of the Pascal's triangle.
//
//  For example, given k = 3,
//  Return [1,3,3,1].
//
//  Note:
//  Could you optimize your algorithm to use only O(k) extra space?

//  Created by Xingye Kan on 4/5/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

//  Remark: rowIndex = 34, negative value appears

#include <iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    
    vector<int> trianglerow;
    
    
    if (rowIndex < 0) {
        trianglerow.clear();
    }
    
    if (rowIndex == 0) {
        trianglerow.push_back(1);
    }
    
    if (rowIndex == 1) {
        trianglerow = getRow(0);
        trianglerow.push_back(1);
    }
    
    
    if (rowIndex > 1) {
        vector<int> row0;
        row0 = getRow(1);
        row0.push_back(0);
        
        
    }
    
    
    
    if (rowIndex > 1) {
        trianglerow.push_back(1);
        
        vector<int> row0 = getRow(1);
        row0.push_back(0);
        
        
        for (int rid = 1; rid <= rowIndex; rid++) {
            for (int cid = 0; cid <= rid; cid++) {
                trianglerow.push_back(row0[cid] + row0[cid+1]);
                
            }
            if (trianglerow.size() == rowIndex + 1) {
                break;
            }
            //trianglerow.push_back(1);
            row0 = trianglerow;
            trianglerow.clear();
            trianglerow.push_back(1);
            row0.push_back(0);
        }
        
        
    }
    
    
    //trianglerow.push_back(1);
    
    return trianglerow;

    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int dim = 34;
    
    vector<int> result = getRow(dim);
    
    for (int i = 0; i < dim+1; i++) {
            cout << result[i] << ' ';
    }

    return 0;
}
