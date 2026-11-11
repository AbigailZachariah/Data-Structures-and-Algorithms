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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==NULL) return new TreeNode(val);

    TreeNode *cur=root;
    while(true){
        if(val>cur->val){
            if(cur->right!=NULL) cur=cur->right;
            else{
                cur->right=new TreeNode(val);
                break;
            }
        }
        else{
            if(cur->left!=NULL) cur=cur->left;
            else{
                cur->left=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

int main() {
    int value;
    cout<<"Enter the value to be inserted:";
    cin>>value;

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

    TreeNode* result=insertIntoBST(root,value);
    cout<<"Inserted successfully";
    
    return 0;
}