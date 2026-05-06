#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node*child;

public:
    Node(int data1, Node *next1,Node *next2)
    {
        data = data1;
        next = next1;
        child=next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child=nullptr;
    }
};

Node *convertArr2VerticalLL(vector<int> &arr)
{
    if(arr.size()==0) return NULL;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->child = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->child;
    }
    cout<<endl;
}

Node*merge(Node*list1,Node*list2){
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data <list2->data){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;

    if(dummyNode->child) dummyNode->child->next=nullptr;
    return dummyNode->child;
}

Node* flattenLinkedList(Node* &head) {
    if(head==NULL||head->next==NULL) return head;
    Node*mergeHead=flattenLinkedList(head->next);
    head=merge(head,mergeHead);
    return head;
}

int main() {
    int n;
    cout << "Enter the number of main nodes (columns): ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter number of elements in column " << i + 1 << ": ";
        cin >> m;
        
        vector<int> colData(m);
        cout << "Enter " << m << " sorted elements for this column: ";
        for (int j = 0; j < m; j++) {
            cin >> colData[j];
        }

        // Convert the input array to a vertical list
        Node* verticalList = convertArr2VerticalLL(colData);

        // Link this vertical list to the main horizontal chain
        if (head == nullptr) {
            head = verticalList;
            tail = head;
        } else {
            tail->next = verticalList;
            tail = tail->next;
        }
    }

    head = flattenLinkedList(head);

    cout << "Final Flattened List: ";
    print(head);

    return 0;
}