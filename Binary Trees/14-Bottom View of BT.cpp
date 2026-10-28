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

vector<int> bottomView(TreeNode *root){
    vector<int>ans;
    if(root==NULL)return ans;
        
    map<int,int>mpp;//vertical,value
    queue<pair<TreeNode*,int>>q;//node,vertical
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();

        TreeNode*node=it.first;
        int line=it.second;

        mpp[line]=node->val;

        if(node->left!=NULL)q.push({node->left,line-1});
        if(node->right!=NULL)q.push({node->right,line+1});
    }
    for(auto i:mpp){
        ans.push_back(i.second);
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

    vector<int>result=bottomView(root);
    for(auto it:result){
        cout<<it<<" ";
    }
    
    return 0;
}