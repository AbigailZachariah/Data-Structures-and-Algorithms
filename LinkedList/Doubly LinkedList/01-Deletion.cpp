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

Node* deleteHead(Node*head){

    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*prev=head;
    head=head->next;
    prev->next=nullptr;
    head->back=nullptr;
    delete(prev);
    return head;
}

Node* deleteTail(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*newTail=tail->back;
    newTail->next=nullptr;
    tail->back=nullptr;
    delete(tail);
    return head;
}

Node* deleteKEle(Node*head,int k){
    if(head==NULL)return NULL;

    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node*prev=temp->back;
    Node*front=temp->next;

    if(prev==NULL && front==NULL){ //single element
        return NULL;
    }

    if(prev==NULL){ //head
        return deleteHead(head);
    }
    
    if(front==NULL){ //tail
        return deleteTail(head);
    }

    prev->next=front;
    front->back=prev;

    temp->back=nullptr;
    temp->next=nullptr;

    delete temp;
    return head;
}

void deleteNode(Node*temp){ 
    Node*prev=temp->back;
    Node*front=temp->next;

    if(front==NULL){ //last element
        prev->next=nullptr;
        temp->back=nullptr;
        delete(temp);
        return;
    }

    prev->next=front;
    front->back=prev;

    temp->back=nullptr;
    temp->next=nullptr;
    delete(temp);
}

int main(){
    vector<int>arr={12,4,5,18,10,7,6};
    Node* head=convertArr2DLL(arr);

    head=deleteHead(head);
    print(head);

    head=deleteTail(head);
    print(head);

    head=deleteKEle(head,4);
    print(head);

    deleteNode(head->next->next);
    print(head);
}
