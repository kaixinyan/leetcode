//
//  main.cpp
//  4sum
//  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

//  Note:
//  Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//  The solution set must not contain duplicate quadruplets.
//  For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//  A solution set is:
//  (-1,  0, 0, 1)
//  (-2, -1, 1, 2)
//  (-2,  0, 0, 2)
//
//  Created by Xingye Kan on 4/15/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    
    vector<vector<int> > solution;
    
    vector<int> quad;
    
    long int length = num.size();
    
    if (length <= 3) {
        return solution;
    }
    
    sort(num.begin(), num.end());
    
    int i = 0;
    int j = i + 1;
    
    long int l = length - 1;
    long int k = l - 1;
    
    
    
    while (l >= 3) {
        while (i < l - 2) {
            if (num[i] + num[j] + num[k] + num[l] < target) {
                j++;
            }
            if (num[i] + num[j] + num[k] + num[l] > target) {
                k--;
            }
            if (j >= k) {
                i++;
                while (num[i] == num[i-1]) {
                    i++;
                }
                j = i + 1;
                k = l - 1;
                continue;
            }
            if (num[i] + num[j] + num[k] + num[l] == target) {
                quad.push_back(num[i]);
                quad.push_back(num[j]);
                quad.push_back(num[k]);
                quad.push_back(num[l]);
                solution.push_back(quad);
                quad.clear();
                j++;
                while (num[j] == num[j-1]) {
                    j++;
                }
                k--;
                while (num[k] == num[k+1]) {
                    k--;
                }
                if (j >= k) {
                    i++;
                    while (num[i] == num[i-1]) {
                        i++;
                    }
                    j = i + 1;
                    k = l - 1;
                }
                
            }
        }
        l--;
        while (num[l] == num[l+1] && l >= 3) {
            l--;
        }
        if (l < 3) {
            return solution;
        }
        i = 0;
        j = i + 1;
        k = l - 1;

    }
    
    
    
    return solution;
}

// solution from leetcode

//vector<vector<int> > fourSum(vector<int> &num, int target) {
//
//vector<vector<int> > res;
//
//if (num.empty())
//return res;
//
//std::sort(num.begin(),num.end());
//
//for (int i = 0; i < num.size(); i++) {
//    
//    int target_3 = target - num[i];
//    
//    for (int j = i + 1; j < num.size(); j++) {
//        
//        int target_2 = target_3 - num[j];
//        
//        int front = j + 1;
//        int back = num.size() - 1;
//        
//        while(front < back) {
//            
//            int two_sum = num[front] + num[back];
//            
//            if (two_sum < target_2) front++;
//            
//            else if (two_sum > target_2) back--;
//            
//            else {
//                
//                vector<int> quadruplet(4, 0);
//                quadruplet[0] = num[i];
//                quadruplet[1] = num[j];
//                quadruplet[2] = num[front];
//                quadruplet[3] = num[back];
//                res.push_back(quadruplet);
//                
//                // Processing the duplicates of number 3
//                while (front < back && num[front] == quadruplet[2]) ++front;
//                
//                // Processing the duplicates of number 4
//                while (front < back && num[back] == quadruplet[3]) --back;
//                
//            }
//        }
//        
//        // Processing the duplicates of number 2
//        while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
//    }
//    
//    // Processing the duplicates of number 1
//    while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
//    
//}
//
//return res;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    //vector<int> numbers = {-13, -12, -12, -12, -11, -11, -10, -9, -9, -8, -8, -8, -8, -7, -7, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 14, 14, 14, 14, 14, 14};
    
    vector<int> numbers = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    
    
    vector<vector<int>> result;
    
    result = fourSum(numbers, -236727523);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
