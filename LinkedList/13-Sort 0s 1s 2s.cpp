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

Node* sortList(Node* &head) {
            
    if(head==NULL || head->next ==NULL ) return head;
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);

    Node*zero=zeroHead;
    Node*one=oneHead;
    Node*two=twoHead;

    Node*temp=head;

    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)? (oneHead->next) : (twoHead->next);
    one->next=twoHead->next;
    two->next=nullptr;

    Node* newHead=zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return newHead;
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
    Node* sorted=sortList(head);
    
    print(sorted);
    
    return 0;
}