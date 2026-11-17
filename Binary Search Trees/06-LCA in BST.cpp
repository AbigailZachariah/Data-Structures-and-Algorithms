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

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root==NULL)return NULL;

    int curr=root->val;
    if(curr<p && curr<q){
        return lowestCommonAncestor(root->right,p,q);
    }
    if(curr>p && curr>q){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}

int main() {
    int p;
    cout<<"Enter p:";
    cin>>p;

    int q1;
    cout<<"Enter q:";
    cin>>q1;

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

    TreeNode* result=lowestCommonAncestor(root,p,q1);
    cout<<result->val;
    
    return 0;
}