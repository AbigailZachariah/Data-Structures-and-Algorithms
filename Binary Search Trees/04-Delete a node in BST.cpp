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

TreeNode*findLastRight(TreeNode*root){
    if(root->right==NULL){
        return root;
    }
    else return findLastRight(root->right);
}

TreeNode*helper(TreeNode* root){
    if(root->right==NULL)return root->left;
    if(root->left==NULL)return root->right;

    TreeNode*rightChild=root->right;
    TreeNode*lastRight=findLastRight(root->left);

    lastRight->right=rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL)return NULL;

    if(root->val==key)return helper(root);

    TreeNode*dummy=root;

    while(root!=NULL){
        if(root->val>key){
            if(root->left!=NULL && root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }
    return dummy;
}

int main() {
    int value;
    cout<<"Enter the value to be Deleted:";
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

    TreeNode* result=deleteNode(root,value);
    cout<<"Deleted successfully";
    
    return 0;
}