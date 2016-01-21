//
//  main.cpp
//  removeNthFromEnd
//
//  Created by Xingye Kan on 7/21/15.
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
    //struct ListNode* second = NULL;
    //struct ListNode* third = NULL;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));   // why do we need '(struct node*)'?
    //second = (struct ListNode*)malloc(sizeof(struct ListNode));
    //third = (struct ListNode*)malloc(sizeof(struct ListNode));
    // allocate 3 nodes in the heap
    head -> val = 1;
    head->next = NULL;
    //second->val = 2;
    //second->next = third;
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



ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode* current = head;
    
    // length is 0
    if(head == NULL) return head;
    
    // length is 1
    if(head -> next == NULL){
        free(head);
        return head;
    }
    
    // length is 2
    if(head -> next -> next == NULL){
        if(n == 2){
            head = head -> next;
        }
        if(n == 1){
            head -> next = NULL;
        }
        return head;
    }
    
    
    int count = 0;
    
    while(current -> next -> next != NULL){
        ++count;
        current = current -> next;
    }
    
    int length = count + 2;
    
    if(n == length){
        head = head -> next;
        return head;
    }
    
    if(n == 1){
        current -> next = NULL;
        return head;
    }
    
    
    
    count = 0;
    
    current = head;
    
    
    while(count != length - 1 - n){
        ++count;
        current = current -> next;
    }
    
    current -> next = current -> next -> next;
    
    return head;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* myList = BuildOneTwoThree();
    cout << removeNthFromEnd(myList,1) << endl;
    return 0;
}
