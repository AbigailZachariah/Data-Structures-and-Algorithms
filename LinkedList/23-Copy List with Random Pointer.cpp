#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node*random;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random=nullptr;
    }
};

Node* convertArr2LL(vector<pair<int, int>> &arr) {
    int n = arr.size();
    if (n == 0) return NULL;

    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(arr[i].first));
    }

    for (int i = 0; i < n; i++) {
        if (i < n - 1) nodes[i]->next = nodes[i + 1];

        int randIdx = arr[i].second; 

        if (randIdx != -1) {
            nodes[i]->random = nodes[randIdx];
        }
    }
    return nodes[0];
}

void print(Node* head) {
    if (!head) {
        cout << "[]" << endl;
        return;
    }

    unordered_map<Node*, int> nodeToIndex;
    Node* temp = head;
    int idx = 0;
    while (temp) {
        nodeToIndex[temp] = idx++;
        temp = temp->next;
    }

    temp = head;
    cout << "[";
    while (temp) {
        cout << "[" << temp->data << ", ";
        if (temp->random == NULL) {
            cout << "null";
        } else {
            cout << nodeToIndex[temp->random];
        }
        cout << "]";
        
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

void insertInBetween(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        Node*copyNode=new Node(temp->data);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }
}

void randomPointers(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        Node*copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
    }
}

Node* deepCopy(Node*head){
    Node* temp=head;
    Node*dummyNode=new Node(-1);
    Node*res=dummyNode;
    
    while(temp!=NULL){
        res->next=temp->next;
        res=res->next;

        temp->next=temp->next->next;
        temp=temp->next;//link rRe-established
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head) {
    insertInBetween(head);
    randomPointers(head);
    return deepCopy(head);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<pair<int, int>> nums;

    for (int i = 0; i < n; i++) {
        int val, randIdx;
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        cout << "Enter random index for node " << i << " (-1 for null): ";
        cin >> randIdx;
        nums.push_back({val, randIdx});
    }

    Node* head = convertArr2LL(nums);
    
    Node* res = copyRandomList(head);

    print(res);

    return 0;
}