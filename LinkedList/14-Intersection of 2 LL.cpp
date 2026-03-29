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

Node *getIntersectionNode(Node *headA, Node *headB) {
    if(headA==NULL||headB==NULL) return NULL;
        
    Node* temp1=headA;
    Node* temp2=headB;

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2 )return temp1;

        if(temp1==NULL) temp1=headB;
        if(temp2==NULL) temp2=headA;
    }
    return temp1;
}

int main(){
    vector<int>nums1={4,1};
    
    vector<int>nums2={5,6,1};

    vector<int>common={8,4,5};

    Node*head1=convertArr2LL(nums1);
    Node*head2=convertArr2LL(nums2);
    Node*Common=convertArr2LL(common);

    Node* temp1 = head1;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = Common; 

    Node* temp2 = head2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = Common; 

    Node* intersect = getIntersectionNode(head1, head2);

    if (intersect != NULL) {
        cout << "Intersected at '" << intersect->data << "'" << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    return 0;
}