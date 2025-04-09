#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while(temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* getIntersection(Node* headA, Node* headB) {
    if(!headA || !headB) return nullptr;
    
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    Node* tempA = headA;
    Node* tempB = headB;
    while(lenA > lenB) {
        if(!tempA) return nullptr;  // Safety check
        tempA = tempA->next;
        lenA--;
    }
    while(lenB > lenA) {
        if(!tempB) return nullptr;  // Safety check
        tempB = tempB->next;
        lenB--;
    }
    
    while(tempA && tempB) {
        if(tempA == tempB) {
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return nullptr;
}

Node* newNode(int data) {
    return new Node(data);
}

void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getLastNode(Node* head) {
    if(!head) return nullptr;
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    // Create List 1: 2->3->8->9
    Node* headA = newNode(2);
    headA->next = newNode(3);
    headA->next->next = newNode(8);
    headA->next->next->next = newNode(9);
    
    // Create List 2: 3->4->5
    Node* headB = newNode(3);
    headB->next = newNode(4);
    headB->next->next = newNode(5);
    
    // Connect List 2's last node to List 1's node with value 8
    Node* tempA = headA;
    while(tempA && tempA->data != 8) {
        tempA = tempA->next;
    }
    if(tempA) {  // Check if node with value 8 was found
        Node* lastB = getLastNode(headB);
        if(lastB) {  // Check if List B has nodes
            lastB->next = tempA;
        } else {
            cout << "List B is empty" << endl;
            return 1;
        }
    } else {
        cout << "Value 8 not found in List A" << endl;
        return 1;
    }
    
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);
    
    Node* intersectionNode = getIntersection(headA, headB);
    if(intersectionNode) {
        cout << "Intersection node value: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }
    
    return 0;
}