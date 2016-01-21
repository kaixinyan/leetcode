//
//  main.cpp
//  reverseBetween


//  Reverse a linked list from position m to n. Do it in-place and in one-pass.

//  For example:
//  Given 1->2->3->4->5->NULL, m = 2 and n = 4,

//  return 1->4->3->2->5->NULL.

//  Note:
//  Given m, n satisfy the following condition:
//  1 ≤ m ≤ n ≤ length of list.
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
    //struct ListNode* third = NULL;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));   // why do we need '(struct node*)'?
    second = (struct ListNode*)malloc(sizeof(struct ListNode));
    //third = (struct ListNode*)malloc(sizeof(struct ListNode));
    // allocate 3 nodes in the heap
    head -> val = 3;
    head->next = second;
    second->val = 5;
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



ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    if (head == NULL || head -> next == NULL || m == n) return head;
    
    ListNode* startNode = head;
    
    
    ListNode* preStart = head;
    
    // find startNode and endNode for reversing, keep record of preStart and sucEnd
    
    int count = 1;
    
    while(count < m){
        ++count;
        preStart = startNode;
        startNode = startNode -> next;
    }
    
    ListNode* endNode = startNode -> next;
    
    ++count;
    
    while(count < n){
        ++count;
        endNode = endNode -> next;
    }
    
    ListNode* sucEnd = NULL;
    
    if(endNode -> next != NULL){
        sucEnd = endNode -> next;
        endNode -> next = NULL;
    }
    
    // reverse partial list
    
    ListNode* second = startNode -> next;
    startNode -> next = NULL;
    
    
    
    ListNode* third = second -> next;
    second -> next = startNode;
    
    ListNode* pre = second;
    ListNode* cur = third;
    
    
    ListNode* nex;
    
    while (cur != NULL){
        nex = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = nex;
    }
    
    
    
    
    
    
    
    // connect to original list
    
    startNode -> next = sucEnd;
    
    if (m == 1) {
        preStart = pre;
        
    }
    
    preStart -> next = pre;
    
    return preStart;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* myList = BuildOneTwoThree();
    reverseBetween(myList, 1, 2);
    return 0;
}
