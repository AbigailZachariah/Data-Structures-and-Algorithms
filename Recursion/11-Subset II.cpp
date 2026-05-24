#include <bits/stdc++.h>
using namespace std;

void func(int ind,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=ind;i<arr.size();i++){
        if(i!=ind && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        func(i+1,arr,ds,ans);
        ds.pop_back();
    }
}
    
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>ds;
    sort(nums.begin(),nums.end());
    func(0,nums,ds,ans);
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

    vector<vector<int>>result=subsetsWithDup(nums);

    for(vector vec:result){
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}