//
//  main.cpp
//  deleteDuplicates
//
//  Created by Xingye Kan on 7/22/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int            val;
    struct ListNode*   next;
};



struct ListNode* BuildOneTwoThree() {
    struct ListNode* head = NULL;
    struct ListNode* second = NULL;
    struct ListNode* third = NULL;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));   // why do we need '(struct node*)'?
    second = (struct ListNode*)malloc(sizeof(struct ListNode));
    third = (struct ListNode*)malloc(sizeof(struct ListNode));
    // allocate 3 nodes in the heap
    head -> val = 1;
    head->next = second;
    second->val = 1;
    second->next = third;
    third->val = 1;
    third->next = NULL;
    // setup first node
    // note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}




ListNode* deleteDuplicates(ListNode* head) {
    
    if(head == NULL || head -> next == NULL) return head;
    
    ListNode* current = head -> next;
    ListNode* precurr = head;
    
    while(current != NULL){
        while(current -> val == precurr -> val){
            
            precurr -> next = current -> next;
            
            
            
            if(current -> next == NULL){
                return head;
            }

            current = current -> next;
            
            
        }
        precurr = current;
        current = current -> next;
        
        
    }
    
    return head;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* myList = BuildOneTwoThree();
    deleteDuplicates(myList);
    cout << myList -> val << endl;
    return 0;
}
