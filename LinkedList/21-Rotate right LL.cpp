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

Node* findNthNode(Node*temp,int k){
    int cnt=1;
    while(temp!=NULL){
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}

Node* rotateRight(Node* head, int k) {
    if(head==NULL||k==0)return head;
    Node*tail=head;
    int len=1;
    while(tail->next!=NULL){
        len++;
        tail=tail->next;
    }
    if(k%len==0)return head;
    k=k%len;

    tail->next=head;
    Node* NthNode=findNthNode(head,len-k);
    head=NthNode->next;
    NthNode->next=NULL;

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
    Node* rotate=rotateRight(head,k);
    
    print(rotate);
    
    return 0;
}