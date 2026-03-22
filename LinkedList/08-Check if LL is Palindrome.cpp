#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node*reverseLL(Node*head){
    if(head==NULL || head->next==NULL) return head;
    Node*newHead=reverseLL(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    if(head==NULL||head->next==NULL) return true;
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL &&    fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*newHead=reverseLL(slow->next);
    Node*first=head;
    Node*second=newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;     
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int number;
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>number;
        nums.push_back(number);
    }
    Node*head=convertArr2LL(nums);
    bool palindrome=isPalindrome(head);
    
    if(palindrome){
        cout<<"Linked List is Palindrome";
    }
    else{
        cout<<"Linked List is not palindrome";
    }
    
    return 0;
}