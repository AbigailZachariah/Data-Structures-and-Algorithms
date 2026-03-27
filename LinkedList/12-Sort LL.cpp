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

Node*middleNode(Node* head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node*temp=dummyNode;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1)temp->next=list1;
    else temp->next=list2;
    return dummyNode->next;
}

Node* sortList(Node* head) {
    if(head==NULL ||head->next==NULL)return head;
    Node*mid=middleNode(head);
        
    Node*right=mid->next;
    mid->next=nullptr;
    Node*left=head;

    left=sortList(left);
    right=sortList(right);

    return mergeTwoLists(left,right);
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