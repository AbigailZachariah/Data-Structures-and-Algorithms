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

TreeNode* helper(vector<int>&inorder ,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>&mpp){
    if(ps>pe || is>ie)return NULL;
    
    TreeNode*root=new TreeNode(postorder[pe]);
    int inRoot=mpp[postorder[pe]];
    int numsLeft=inRoot-is;

    root->left=helper(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mpp);
    root->right=helper(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mpp);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size())return NULL;
    map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
} 

int main() {
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;

    vector<int> postorder(number);
    cout << "Enter the postorder elements:\n";
    for(int i = 0; i < number; i++) {
        cin >> postorder[i];
    }

    vector<int> inorder(number);
    cout << "Enter the inorder elements:\n";
    for(int i = 0; i < number; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(postorder, inorder);
    cout << "Tree built successfully!" << endl;

    return 0;
}