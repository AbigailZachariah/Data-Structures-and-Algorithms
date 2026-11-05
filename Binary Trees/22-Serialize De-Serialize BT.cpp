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

string serialize(TreeNode* root) {
    if(root == NULL)return "#";

    string s;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();

        if(node==NULL) s.append("#,");
        else {
            s.append(to_string(node->val)+',');
        }
        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data) {
    if(data.size()==0 || data=="#")return NULL;

    queue<TreeNode*>q;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    q.push(root);

    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#"){
            node->left=NULL;
        }
        else{
            TreeNode* nodeLeft=new TreeNode(stoi(str));
            node->left=nodeLeft;
            q.push(nodeLeft);
        }

        getline(s,str,',');
        if(str=="#"){
            node->right=NULL;
        }
        else{
            TreeNode* nodeRight=new TreeNode(stoi(str));
            node->right=nodeRight;
            q.push(nodeRight);
        }
    }
    return root;
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

    string str=serialize(root);
    cout<<str;

    TreeNode* de_serial=deserialize(str);
    if(de_serial!=NULL)cout<<"\nSucessful";
    else cout<<"Unsucessful";
    
    return 0;
}