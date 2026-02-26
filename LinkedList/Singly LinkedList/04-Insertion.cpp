#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
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

Node* insertHead(Node*head,int val){
    Node* temp=new Node(val,head);
    return temp;
}

Node* insertTail(Node*head,int val){
    if(head==NULL)return new Node(val);
    Node*temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

Node* insertAtPos(Node*head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertValBefore(Node*head,int val,int Value){
    if(head==NULL){
        return NULL;
    }
    if(head->data==Value){
        Node* temp=new Node(val,head);
        return temp;
    }

    Node*temp=head;
    while(temp->next!=NULL){

        if(temp->next->data==Value){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={2,4,5,8};
    Node* head=convertArr2LL(arr);

    head=insertHead(head,1);
    print(head);

    head=insertTail(head,10);
    print(head);

    head=insertAtPos(head,9,2);
    print(head);

    head=insertValBefore(head,11,8);
    print(head);
}