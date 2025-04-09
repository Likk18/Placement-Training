#include<iostream>
using namespace std;

class node {
    public:
    node *next;
    int data;
    node(int val) {
        data = val;
        next = nullptr;
    }
};

node* mergesort(node* headA, node* headB) {
    node dummy(0);
    node* headC = &dummy;

    while(headA && headB) {
        if(headA->data <= headB->data) {
            headC->next = headA;
            headA = headA->next;
        } else {
            headC->next = headB;
            headB = headB->next;
        }
        headC = headC->next;
    }

    if(headA) {
        headC->next = headA;
    }
    if(headB) {
        headC->next = headB;
    }

    return dummy.next;
}

int main() {
    node* headA = new node(1);
    headA->next = new node(2);
    headA->next->next = new node(3);
    node* headB = new node(4);
    headB->next = new node(5);
    headB->next->next = new node(6);
    node* merged = mergesort(headA, headB);
    
    node* temp = merged;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}