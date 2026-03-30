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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
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

    vector<int>nums2;
    int n2;
    cout<<"Enter number of elements for 2nd LL: ";
    cin>>n2;

    cout<<"Enter the element: ";
    for(int i=0;i<n2;i++){
        cin>>number;
        nums2.push_back(number);
    }

    Node*head=convertArr2LL(nums);
    Node*head2=convertArr2LL(nums2);

    Node* add=addTwoNumbers(head,head2);
    
    if(add!=NULL){
        print(add);
    }
    else{
        cout<<"Result list is empty";
    }
    
    return 0;
}