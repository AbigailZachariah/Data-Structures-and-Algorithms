#include <bits/stdc++.h>
using namespace std;


void findCombo(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        ds.push_back(arr[i]);
        findCombo(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
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
    vector<vector<int>>result=combinationSum2(nums,k);

    for(vector vec:result){
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}