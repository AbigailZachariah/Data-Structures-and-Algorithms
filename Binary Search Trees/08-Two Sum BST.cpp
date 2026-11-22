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


 class BSTIterator{
    stack<TreeNode*> st;
    bool before=true;

	public:
		BSTIterator(TreeNode* root,bool isBefore){
            before=isBefore;
			pushAll(root);
		}
		
		bool hasNext(){
			return !st.empty();
		}
		
		int next(){
            TreeNode* temp=st.top();
            st.pop();

            if(!before){
                pushAll(temp->right);
            }
            else pushAll(temp->left);
            return temp->val;
		}
    private:
        void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);

            if(before==true){
                root=root->right;
            }
            else root=root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL )return false;

        //next
        BSTIterator l(root,false);

        //before
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k)return true;
            else if (i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
    }
};

int main() {
    int k;
    cout<<"Enter value of k:";
    cin>>k;

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
    bool result=sol.findTarget(root,k);
    
    if(result==1)cout<<"There Exists";
    else cout<<"There does not Exists";

    return 0;
}