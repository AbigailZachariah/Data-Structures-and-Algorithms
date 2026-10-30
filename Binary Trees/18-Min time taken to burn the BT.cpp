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

int maxTime(map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
    queue<TreeNode*>q;
    q.push(target);

    map<TreeNode*,int>vis;
    vis[target]=1;

    int maxi=0;

    while(!q.empty()){
                
        int n=q.size();
        int flag=0;

        for(int i=0;i<n;i++){
            auto node=q.front();
            q.pop();

            if(node->left && !vis[node->left]){
                flag=1;
                vis[node->left]=1;
                q.push(node->left);
            }

            if(node->right && !vis[node->right]){
                flag=1;
                vis[node->right]=1;
                q.push(node->right);
            }

            if(mpp[node] && !vis[mpp[node]]){
                flag=1;
                vis[mpp[node]]=1;
                q.push(mpp[node]);
            }
        }
        if(flag)maxi++;
    }
    return maxi;
}

TreeNode* markParents(TreeNode*root,map<TreeNode*,TreeNode*>&mpp,int start){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* target;

    while(!q.empty()){
        TreeNode*node=q.front();
        if(node->val==start)target=node;
        q.pop();

        if(node->left){
            mpp[node->left]=node;
            q.push(node->left);
        }

        if(node->right){
            mpp[node->right]=node;
            q.push(node->right);
        }
    }
    return target;
}

int timeToBurnTree(TreeNode* root, int start){
    map<TreeNode*,TreeNode*>mpp;
    TreeNode* target=markParents(root,mpp,start);
    int time=maxTime(mpp,target);
    return time;
}

int main() {
    int start;
    cout<<"Enter start:";
    cin>>start;

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

    cout<<timeToBurnTree(root,start);
    
    return 0;
}