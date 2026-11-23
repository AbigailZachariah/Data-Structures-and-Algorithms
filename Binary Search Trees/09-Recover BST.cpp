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

class solution{
    private:
        TreeNode*prev;
        TreeNode*first;
        TreeNode*middle;
        TreeNode*last;

    public:
        void inorder(TreeNode*root){
            if(root==NULL)return;
            inorder(root->left);

            if(prev!=NULL && root->val<prev->val){

                if(first==NULL){
                    first=prev;
                    middle=root;
                }
                last=root;
            }
            prev=root;
            inorder(root->right);
        }

        void recoverTree(TreeNode* root) {
            first=last=middle=NULL;
            prev=new TreeNode(INT_MIN);

            inorder(root);

            if(first && last)swap(first->val,last->val);
            else if(first && middle)swap(first->val,middle->val);
        }

        void printInorder(TreeNode* node) {
            if (node == nullptr) return;
            printInorder(node->left);
            cout << node->val << " ";
            printInorder(node->right);
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

    solution sol;
    sol.recoverTree(root);

    cout << "Recovered tree (inorder): ";
    sol. printInorder(root);
    cout << endl;

    return 0;
}