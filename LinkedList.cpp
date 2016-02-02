//
//  main.cpp
//  LinkedList
//
//  Created by Xingye Kan on 7/21/15.
//  Copyright (c) 2015 Xingye Kan. All rights reserved.
//

#include <iostream>

using namespace std;



struct node {
    int            data;
    struct node*   next;
};

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    head = (struct node*)malloc(sizeof(struct node));   // why do we need '(struct node*)'?
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    // allocate 3 nodes in the heap
    head -> data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    // setup first node
    // note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}


int Length(struct node* head) {
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node* myList = BuildOneTwoThree();
    cout << Length(myList) << endl;
    return 0;
}
