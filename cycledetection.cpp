#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val) : data(val), next(nullptr) {}
};

bool detectCycle(node* head) {
    if (!head || !head->next) return false;
    node* slow = head;
    node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    cout << (detectCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}