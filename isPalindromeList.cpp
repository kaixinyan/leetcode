//
//  main.cpp
//  isPalindromeList

//  Given a singly linked list, determine if it is a palindrome.

//  Follow up:
//  Could you do it in O(n) time and O(1) space?
//
//  Created by Xingye Kan on 7/24/15.
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

ListNode* reverse(ListNode* head){
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




bool isPalindrome(ListNode* head) {
    
    // length
    
    int len = 0;
    ListNode* cur = head;
    
    while(cur != NULL){
        ++len;
        cur = cur -> next;
    }
    
    if(len <= 1) return true;
    
    if(len == 2){
        if (head -> val == head -> next -> val) return true;
        else return false;
    }
    
    // find middle node
    
    int mid;
    if(len%2 == 0) mid = len/2+1;
    else mid = (len+1)/2;
    
    
    int count = 1;
    cur = head;
    
    
    while(count < mid - 1){
        ++count;
        cur = cur -> next;
    }
    
    ListNode* newHead;
    
    if(len%2 == 0) newHead = cur -> next;
    else newHead = cur -> next -> next;
    
    ListNode* secondHalf =  reverse(newHead);
    
    
    ListNode* cur1 = head;
    ListNode* cur2 = secondHalf;
    
    
    
    while(cur2 != NULL){
        if(cur1 -> val == cur2 -> val){
            cur2 = cur2 -> next;
            cur1 = cur1 -> next;
        }
        else {
            if(len%2 == 0) cur -> next = reverse(secondHalf);
            else cur -> next -> next = reverse(secondHalf);
            return false;
        }
    }
    
    if(len%2 == 0) cur -> next = reverse(secondHalf);
    else cur -> next -> next = reverse(secondHalf);
    
    return true;
    
    
    
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
