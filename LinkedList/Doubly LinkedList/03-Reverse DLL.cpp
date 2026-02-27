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

Node* reverseDLL(Node*head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* last=NULL;
    Node* current=head;

    while(current!=NULL){
        last=current->back;
        current->back=current->next;
        current->next=last;

        // To go to next node
        current=current->back;
    }
    return last->back;
}

int main(){
    vector<int>arr={12,4,5,18,10};
    Node* head=convertArr2DLL(arr);

    head=reverseDLL(head);
    print(head);
}