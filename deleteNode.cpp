//
//  main.cpp
//  deleteNode
//

//  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

//  Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

//  Created by Xingye Kan on 7/22/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>

struct ListNode {
    int            val;
    struct ListNode*   next;
};

void deleteNode(ListNode* node) {
    
    *(node) = *(node -> next);
    
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
