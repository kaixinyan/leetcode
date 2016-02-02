//
//  main.cpp
//  merge

//  Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//  Note:
//  You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
//
//  Created by Xingye Kan on 3/30/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n) {
    int idA = 0;
    int count = 0;
    
    if(m < 0 || n <= 0) return;
    
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            A[i] = B[i];
        }
    }
    
    
    
    if (m > 0 && n > 0) {
        while (n - count != 0) {
            if (B[0] < A[idA]) {
                for (int i = m + count; i > idA; i--) {
                    A[i] = A[i-1];
                }
                A[idA] = B[0];
                for (int i = 1; i < n - count; i++) {
                    B[i-1] = B[i];
                }
                
                count++;
            }
            idA++;
            if (B[0] >= A[m + count - 1]) {
                for (int i = m + count; i < m + n; i++) {
                    A[i] = B[i-m-count];
                }
                break;
            }
        }
        
    }
        
    return;
    }

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[] = {2};
    int m = 1;
    int B[] = {4};
    int n = 1;
    merge(A, m, B, n);
    
    for (int i = 0; i < m + n; i++) {
        cout << A[i] << endl;
    }
    
    return 0;
}
