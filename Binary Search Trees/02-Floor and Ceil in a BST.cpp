#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> floorCeilOfBST(TreeNode* root,int key){
    vector<int>ans;
    int floor=-1,ceil=-1;

    while(root){
        if(key==root->val){
            floor=root->val;
            ceil=root->val;
            ans.push_back(floor);
            ans.push_back(ceil);
            return ans;
        }
        else if(key > root-> val){
            floor=root->val;
            root=root->right;
        }
        else{
            ceil=root->val;
            root=root->left;
        }
    }
    ans.push_back(floor);
    ans.push_back(ceil);
    return ans;
}

int main() {
    int rootVal;
    cout << "Enter root value (-1 for empty): ";
    if (!(cin >> rootVal) || rootVal == -1) {
        cout << "Tree is empty." << endl;
        return 0;
    }

    TreeNode* root = new TreeNode(rootVal);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal;
        cout << "Enter left child of " << curr->val << " (-1 for null): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        int rightVal;
        cout << "Enter right child of " << curr->val << " (-1 for null): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }
    int key;
    cout<<"Enter the value to be searched:";
    cin>>key;

    vector<int>result=floorCeilOfBST(root,key);
    for(auto it:result){
        cout<<it<<" ";
    }
    
    return 0;
}