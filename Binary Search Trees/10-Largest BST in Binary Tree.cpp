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


class NodeValue{
    public:
    int minNode, maxNode,maxSize;

    NodeValue(int minNode,int maxNode,int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};
class Solution{
	public:
        NodeValue helper(TreeNode*root){
            if(!root) return NodeValue(INT_MAX,INT_MIN,0);
        
            auto left=helper(root->left);
            auto right=helper(root->right);

            if(left.maxNode < root->val && root->val < right.minNode){
                return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode),left.maxSize+right.maxSize+1);
            }
            return NodeValue(INT_MIN, INT_MAX,max(left.maxSize,right.maxSize));
        }
        int largestBST(TreeNode* root){
            return helper(root).maxSize;
		}
};

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

    Solution sol;
    cout<<sol.largestBST(root);
    return 0;
}