#include<iostream>
#include<stack>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val) : data(val), next(nullptr) {}
};

bool isPalindrome(node* head) { 
    stack<int> s;
    node* temp = head;
    while(temp) {
        s.push(temp->data);
        temp = temp->next;
    }
    while(head) {
        if(head->data != s.top()) {
            return false;
        }
        s.pop();
        head = head->next;
    }
    return true;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(2);
    head->next->next->next = new node(1);
    
    cout << (isPalindrome(head) ? "Is Palindrome" : "Not Palindrome") << endl;
    
    return 0;
}