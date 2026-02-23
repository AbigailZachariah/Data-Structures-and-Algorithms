#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArray2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head; //mover initially at head

    //iterating through entire array other than the first element 
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp; //linking
        mover=temp; //moving mover to the next 
    }
    return head;
}

int main(){
    vector<int>arr={2,5,8,7};

    //self defined datatype
    Node* head=convertArray2LL(arr);
    cout<<head->data;
}