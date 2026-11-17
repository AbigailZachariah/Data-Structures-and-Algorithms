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

TreeNode* successor(TreeNode*root,int key){
    TreeNode*s=NULL;
    while(root!=NULL){
        if(root->val<=key){
            root=root->right;
        }
        else{
            s=root;
            root=root->left;
        }
    }
    return s;
}

TreeNode* predecessor(TreeNode*root,int key){
    TreeNode*p=NULL;
    while(root!=NULL){
        if(root->val>=key){
            root=root->left;
        }
        else{
           p=root;
           root=root->right;
        }
    }
    return p;
}

vector<int> succPredBST(TreeNode* root,int key){
    vector<int>ans;
    TreeNode*pre=predecessor(root,key);
    TreeNode*suc=successor(root,key);
    ans.push_back(pre->val);
    ans.push_back(suc->val);
    return ans;
}

int main() {
    int p;
    cout<<"Enter p:";
    cin>>p;

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

    vector result=succPredBST(root,p);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}