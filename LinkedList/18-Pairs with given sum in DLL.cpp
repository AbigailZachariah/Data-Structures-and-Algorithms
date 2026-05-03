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

Node* findTail(Node* head){
    Node*tail=head;
    while(tail->next!=NULL) tail=tail->next;
    return tail;
}

vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
    vector<vector<int>>ans;
    Node*left=head;
    Node*right=findTail(head);
    while(left->data<right->data){
        if(left->data+right->data==target){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
        else if(left->data+right->data<target){
            left=left->next;
        }
        else right=right->back;
    }
    return ans;
}

int main(){
    vector<vector<int>>ans;
    vector<int>nums;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int target;
    cout<<"Enter the sum: ";
    cin>>target;

    int number;
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>number;
        nums.push_back(number);
    }
    Node*head=convertArr2DLL(nums);

    ans=findPairsWithGivenSum(head,target);    
    
    for(auto ele:ans){
        for(auto it:ele){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}