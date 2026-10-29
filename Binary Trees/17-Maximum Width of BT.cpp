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

int widthOfBinaryTree(TreeNode* root) {
    if(root==NULL)return 0;
    queue<pair<TreeNode*,int>>q;
    int maxWidth=0;
    q.push({root,0});

    while(!q.empty()){
        int first,last;
        long long mini=q.front().second; //storing the minimal in each level
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* node=q.front().first;
            long long cur_id=q.front().second-mini;
            q.pop();

            if(i==0)first=cur_id;
            if(i==n-1)last=cur_id;

            if(node->left)q.push({node->left,cur_id*2+1});
            if(node->right)q.push({node->right,cur_id*2+2});
        }
        maxWidth=max(maxWidth,last-first+1);
    }
    return maxWidth;
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

    cout<<widthOfBinaryTree(root);
    
    return 0;
}