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

Node* insertBeforeHead(Node*head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

Node* insertBeforeTail(Node*head,int val){
    if(head->next==NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node*prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}

Node* insertBeforeKth(Node*head,int val,int k){

    if(k==1) return insertBeforeHead(head,val) ;

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
    Node* newNode=new Node(val,temp,prev);

    prev->next=newNode;
    temp->back=newNode;
    return head;
}

void insertBeforeNode(Node*node,int val){ 
    Node*prev=node->back;
    Node* newNode=new Node(val,node,prev);

    node->back=newNode;
    prev->next=newNode;
}

int main(){
    vector<int>arr={12,4,5,18,10};
    Node* head=convertArr2DLL(arr);

    head=insertBeforeHead(head,6);
    print(head);

    head=insertBeforeTail(head,8);
    print(head);

    head=insertBeforeKth(head,3,4);
    print(head);

    insertBeforeNode(head->next->next,1);
    print(head);
}
