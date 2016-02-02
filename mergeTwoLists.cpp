//
//  main.cpp
//  mergeTwoLists

//  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

//  Created by Xingye Kan on 7/22/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>

struct ListNode {
    int            val;
    struct ListNode*   next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    //if(l1 == NULL) return l2;
    //if(l2 == NULL) return l1;
    
    
    
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
   
    while (cur1 != NULL && cur2 != NULL) {
        while (cur1 -> val <= cur2 -> val) {
            
            cur1 = cur1 -> next;
            
            
        }
        while (cur1 -> val >= cur2 -> val) {
            cur2 = cur2 -> next;
        }
    }
    
    if (l1 -> val <= l2 -> val) {
        return l1;
    }
    else return l2;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
