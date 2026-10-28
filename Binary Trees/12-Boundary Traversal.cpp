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

bool isLeaf(TreeNode* node) {
    if (node == nullptr) return false;
    return (node->left == nullptr && node->right == nullptr);
}

void leftBounday(TreeNode*root,vector<int>&res){
    TreeNode*cur=root->left;
    while(cur){
        if(!isLeaf(cur))res.push_back(cur->val);
        if(cur->left)cur=cur->left;
        else cur=cur->right;
    }
}

void rightBounday(TreeNode*root,vector<int>&res){
    TreeNode*cur=root->right;
    vector<int>temp;
    while(cur){
        if(!isLeaf(cur))temp.push_back(cur->val);
        if(cur->left)cur=cur->right;
        else cur=cur->left;
    }
    for(int i= temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

void leaves(TreeNode*root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)leaves(root->left,res);
    if(root->right)leaves(root->right,res);
}

vector <int> boundary(TreeNode* root){
    vector<int>res;
    if(root==NULL)return res;
    if(!isLeaf(root)) res.push_back(root->val);

    leftBounday(root,res);
    leaves(root,res);
    rightBounday(root,res);

    return res;
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

    vector<int>result=boundary(root);
    for(auto it:result){
        cout<<it<<" ";
    }
    
    return 0;
}