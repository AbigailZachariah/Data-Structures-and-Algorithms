#include <bits/stdc++.h>
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

void print (Node*head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeHead(Node* head){
    if(head==NULL)return head;
    Node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    //empty or one element
    if(head==NULL||head->next==NULL)return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}

Node* removePos(Node* head,int k){
    if(head==NULL)return NULL;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int cnt=0;
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeVal(Node*head,int val){
    if(head==NULL)return NULL;
    if(head->data==val){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;

    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int>arr={2,4,5,8};
    Node* head=convertArr2LL(arr);

    head=removeHead(head);
    print(head);

    head=removeTail(head);
    print(head);

    head=removePos(head,2);
    print(head);

    head=removeVal(head,2);
    print(head);
}
