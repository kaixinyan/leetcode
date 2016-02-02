//
//  main.cpp
//  removeElementsLinkedList
//
//  Created by Xingye Kan on 6/24/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

//  Remove all elements from a linked list of integers that have value val.

//  Example
//  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//  Return: 1 --> 2 --> 3 --> 4 --> 5


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    second->val = 2;
    second->next = third;
    third->val = 3;
    third->next = NULL;
    // setup first node
    // note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}



ListNode* removeElementsLinkedList(ListNode* head, int val) {
    
    
    // length is 0
    if(head == NULL) return head;
    
    while(head -> val == val){
        head = head -> next;
        if(head == NULL){
            return head;
        }
    }
    
    ListNode* current = head;
    
    
    // length is 1
    if(head -> next == NULL){
        return head;
    }
    
    // length is 2
    if(head -> next -> next == NULL){
        if(head -> next -> val == val){
            head -> next = NULL;
        }
        return head;
    }
    
    // length is 2+
    if(head -> next -> next != NULL){
         while(current -> next -> next != NULL){
            if(current -> next -> val == val){
               current -> next = current -> next -> next;
               
            }
            else current = current -> next;
             
        }
        
        if(current -> next -> val == val){
            current -> next = NULL;
        }
        
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct ListNode* myList = BuildOneTwoThree();
    //cout << removeElementsLinkedList(myList,1) << endl;
    cout << myList << endl;
    cout << myList->next << endl;
    
    int a = 1;
    
    int* p;
    p = &a;
    
    cout << p << endl;
    cout << *p << endl;
    
    return 0;
}
