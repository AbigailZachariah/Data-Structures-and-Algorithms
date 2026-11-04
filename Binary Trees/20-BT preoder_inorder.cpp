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

TreeNode*helper(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&mpp){
    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }
    TreeNode*root=new TreeNode(preorder[preStart]);
    int inRoot=mpp[root->val];
    int numsLeft=inRoot-inStart;
    root->left=helper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,mpp);
    root->right=helper(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mpp);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    TreeNode*root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}

int main() {
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;

    vector<int> preorder(number);
    cout << "Enter the preorder elements:\n";
    for(int i = 0; i < number; i++) {
        cin >> preorder[i];
    }

    vector<int> inorder(number);
    cout << "Enter the inorder elements:\n";
    for(int i = 0; i < number; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);
    cout << "Tree built successfully!" << endl;

    return 0;
}