#include <bits/stdc++.h>
using namespace std;

void findCombo(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    //pick element
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findCombo(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
    //not pick element
    findCombo(ind+1,target,arr,ans,ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    findCombo(0,target,candidates,ans,ds);
    return ans;
}

int main() {

    int n;
    cout<<"Enter the number of elements:";
    cin>>n;

    vector<int> nums;

    int ele;
    cout<<"Enter the elements:";

    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    int k;
    cout<<"Enter the target sum:";
    cin>>k;

    cout<<"Combinations of Candidates: ";
    vector<vector<int>>result=combinationSum(nums,k);

    for(vector vec:result){
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}