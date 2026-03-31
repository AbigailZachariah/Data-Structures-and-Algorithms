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

int addHelper(Node*temp){
    if(temp==NULL)return 1;
    int carry=addHelper(temp->next);
    temp->data+=carry;
    if(temp->data<10) return 0;
    temp->data=0;
    return 1;
}
Node *addOne(Node *head) {
    int carry=addHelper(head);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
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
    Node*head=convertArr2LL(nums);

    Node* add=addOne(head);
    
    print(add);
    
    return 0;
}