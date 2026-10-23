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

bool helper(TreeNode*left,TreeNode*right){
    if(left==NULL||right==NULL)return left==right;

    if(left->val!=right->val)return false;
    return helper(left->right,right->left) && helper(left->left,right->right);
}

bool isSymmetric(TreeNode* root) {
    return root==NULL||helper(root->left,root->right);
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

    cout<<isSymmetric(root);
    return 0;
}