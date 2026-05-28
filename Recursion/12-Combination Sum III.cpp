#include <bits/stdc++.h>
using namespace std;

void func(int sum,int k,vector<int>&nums,int num,vector<vector<int>>&ans){
    if(sum==0 && nums.size()==k) {
        ans.push_back(nums);
        return;
    }
    if(sum<=0 || nums.size()>k){
        return;
    }
    for (int i=num;i<=9;i++){
        if(i<=sum){
            nums.push_back(i);
            func(sum-i,k,nums,i+1,ans);
            nums.pop_back();
        }
        else break;
    }

}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>ans;
    vector<int>nums;
    func(n,k,nums,1,ans);
    return ans;
}

int main() {

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    int n;
    cout<<"Enter the target sum:";
    cin>>n;

    vector<vector<int>>result=combinationSum3(k,n);

    for(vector vec:result){
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}