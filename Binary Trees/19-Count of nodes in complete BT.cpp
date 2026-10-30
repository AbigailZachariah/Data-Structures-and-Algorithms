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

int leftHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}

int rightHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(root==NULL)return 0;

    int lh=leftHeight(root);
    int rh=rightHeight(root);

    if(lh==rh) return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
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

    cout<<countNodes(root);
    
    return 0;
}