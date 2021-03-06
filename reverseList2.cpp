//
//  main.cpp
//  reverseList2 iterative
//
//  Created by Xingye Kan on 7/23/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>

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
    second->val = 2;
    second->next = NULL;
    //third->val = 3;
    //third->next = NULL;
    // setup first node
    // note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}

ListNode* reverseList(ListNode* head) {
    
    // length is 0 or 1
    if (head == NULL || head -> next == NULL) return head;
    
    ListNode* second = head -> next;
    head -> next = NULL;
    
    
    ListNode* third = second -> next;
    second -> next = head;
    
    if (third == NULL) return second;
    
    ListNode* cur = third;
    ListNode* pre = second;
    ListNode* nex;
    
    while (cur != NULL){
        nex = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nex;
    }
    
    
    return pre;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* myList = BuildOneTwoThree();
    reverseList(myList);

    return 0;
}
