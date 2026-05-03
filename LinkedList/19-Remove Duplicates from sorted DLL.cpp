#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node*next1,Node*back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertArr2DLL(vector<int>arr){
    Node*head=new Node(arr[0]);
    Node*prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node * removeDuplicates(Node *head) {
    Node*temp=head;
    while(temp!=NULL && temp->next!=NULL){
    Node* nextNode=temp->next;
        while(nextNode!=NULL&& nextNode->data==temp->data){
            Node*duplicate=nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode!=NULL) nextNode->back=temp;
        temp=temp->next;
    }
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
    Node*head=convertArr2DLL(nums);

    Node* duplicate=removeDuplicates(head);
    
    print(duplicate);
    
    return 0;
}