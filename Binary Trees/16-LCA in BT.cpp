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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q)return root;

    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);

    if(left==NULL )return right;
    else if (right==NULL)return left;
    else return root; // both the left and right are not NULL;
}

int main() {
    int P;
    cout << "Enter p: ";
    cin >> P;
    TreeNode* p = new TreeNode(P);

    int Q;
    cout << "Enter q: ";
    cin >> Q;
    TreeNode* q1 = new TreeNode(Q);

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

    auto findNode = [](TreeNode* rootNode, int target) -> TreeNode* {
        if (!rootNode) return nullptr;
        queue<TreeNode*> tempQ;
        tempQ.push(rootNode);
        while (!tempQ.empty()) {
            TreeNode* currNode = tempQ.front();
            tempQ.pop();
            if (currNode->val == target) return currNode;
            if (currNode->left) tempQ.push(currNode->left);
            if (currNode->right) tempQ.push(currNode->right);
        }
        return nullptr;
    };

    p = findNode(root, P);
    q1 = findNode(root, Q);

    TreeNode* result = lowestCommonAncestor(root, p, q1);
    if (result != nullptr) {
        cout << result->val << endl;
    }

    return 0;
}