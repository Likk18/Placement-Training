#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int val){
        data = val;
        next = NULL;
    }
};
void printList(node* head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }cout<<"null"<<endl;
}
void reverseList(node** head)
{
    node* prev = NULL;
    node* curr = *head;
    node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void insertAtTail(node** head,int value)
{
    node* newNode = new node(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main()
{
    node* head=nullptr;
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        insertAtTail(&head,arr[i]);
    }
    cout<<"Original List: ";
    printList(head);
    reverseList(&head);
    cout<<"Reversed List: ";
    printList(head);
    return 0;

}