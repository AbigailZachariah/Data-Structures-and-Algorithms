#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
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

Node* reverseLinkedList(Node*head){
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* getKthNode(Node*temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    Node*temp=head;
    Node*prevLast=NULL;
    while(temp!=NULL){
        Node*KthNode=getKthNode(temp,k);
        if(KthNode==NULL){
            if(prevLast) prevLast->next=temp;
            break;
        }
        Node*nextNode=KthNode->next;
        KthNode->next=NULL;

        reverseLinkedList(temp);
        if(temp==head){
            head=KthNode;
        }
        else prevLast->next=KthNode;
        prevLast=temp;
        temp=nextNode;
    }
    return head;
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int k;
    cout<<"K Number:";
    cin>>k;

    int number;
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>number;
        nums.push_back(number);
    }

    Node*head=convertArr2LL(nums);
    Node* reverse_grp=reverseKGroup(head,k);
    
    print(reverse_grp);
    
    return 0;
}