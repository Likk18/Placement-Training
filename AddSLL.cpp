#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int val):data(val),next(NULL){}
};
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
void printList(node* head)
{
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }cout<<"null"<<endl;
}
node* addTwoNumbers(node* l1, node* l2)
{
    int i;
    node* dummy = new node(0);
    node* curr=dummy;
    int carry = 0;
    while(l1 != nullptr && l2 != nullptr || carry != 0)
    {
        int sum = carry;
        if(l1 != nullptr)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new node(sum%10);
        curr = curr->next;
    }
    return dummy->next;
}
int main()
{
    int i;
    node* l1 = nullptr;
    node* l2 = nullptr;
    int arr1[] = {2, 4, 3}; //342
    int arr2[] = {5, 6, 4}; //465
    for(i=0;i<3;i++)
    {
        insertAtTail(&l1, arr1[i]);
        insertAtTail(&l2, arr2[i]);
    }
    cout << "First Number" << endl;
    printList(l1);
    cout << "Second Number" << endl;
    printList(l2);
    node* result = addTwoNumbers(l1, l2);
    cout << "Result" << endl;
    printList(result);
    return 0;
}