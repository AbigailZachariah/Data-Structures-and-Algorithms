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

int findLengthOfLoop(Node *head){
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow){
            int cnt = 1;
            fast = fast->next;
            while (slow != fast){
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
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
    
    Node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head->next;
    int length=findLengthOfLoop(head);

    if(length==0){
        cout<<"No cycle found in the list"<<endl;
    }
    else{
        cout<<length;
    }
    return 0;
}