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

Node * deleteAllOccurrences(Node* head, int target) {
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            if(temp==head){
                head=temp->next;
            }
            Node*nextNode=temp->next;
            Node*prevNode=temp->back;
            if(nextNode!=NULL)nextNode->back=prevNode;
            if(prevNode!=NULL)prevNode->next=nextNode;
            delete(temp);
            temp=nextNode;
        }
        else temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int target;
    cout<<"Enter the key: ";
    cin>>target;

    int number;
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>number;
        nums.push_back(number);
    }
    Node*head=convertArr2DLL(nums);

    Node* key=deleteAllOccurrences(head,target);
    
    print(key);
    
    return 0;
}