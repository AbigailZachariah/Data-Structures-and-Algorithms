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

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeNthFromEnd(Node* head, int n) {
    Node*slow=head;
    Node*fast=head;
    for(int i=0;i<n;i++) fast=fast->next;
    if(fast==NULL) return head->next;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node*delNode=slow->next;
    slow->next=slow->next->next;
    delete(delNode);
    return head;
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

    int N;
    cout<<"Enter the value of N";
    cin>>N;

    Node*head=convertArr2LL(nums);
    Node* Nthnode=removeNthFromEnd(head,N);
    
    print(Nthnode);
    
    return 0;
}