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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    if(root==NULL)return ans;

    queue<TreeNode*>q;
    q.push(root);
    bool LTR=true;
    
    while(!q.empty()){
        int n=q.size();
        vector<int>row(n);

        for(int i=0;i<n;i++){
            TreeNode*node=q.front();
            q.pop();

            if(node->left!=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);

            int index=(LTR)? i : (n-1-i);
            row[index]=node->val;
        }
        LTR=!LTR;
        ans.push_back(row);
    }
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

    vector<vector<int>>result=zigzagLevelOrder(root);
    for(auto row:result){
        for(int it:row){
            cout<<it<<" ";
        }
    }
    return 0;
}